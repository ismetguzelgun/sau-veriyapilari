/**
* @file 		HuffmanAgaci.cpp
* @description 	HuffmanAgaci oluþturan cpp dosyasý
* @course		1-B
* @assignment	5
* @date			15.12.2014
* @author		Ýsmet GÜZELGÜN b121210025@sakarya.edu.tr
*		 		Ýbrahim AKDAÐ  b121210027@sakarya.edu.tr		  
*/
#include "HuffmanAgaci.hpp"
/**
 *HuffmanAgaci yýkýcýsý
 *
 */
HuffmanAgaci::HuffmanAgaci()
{
			harfler = 256;
			girdi="";
			root=NULL;
			sonuc="";
}
/**
 *HuffmanAgaci dosya okuyan fonksiyon
 *
 */
void HuffmanAgaci::DosyaOku(string dosyaYolu)
{
	girdi+=dosyaYolu;
	girdi+='\n';
}
/**
 *HuffmanAgaci kodlayan fonksiyon
 *
 */
void HuffmanAgaci::Kodla()
{
	char karakterler[girdi.size()-1];
	
	strcpy(karakterler, girdi.c_str());
	
	//Frekanslarý say
	int frek[harfler]; 
	// frekanslarý sýfýrla
	for(int i=0;i<harfler;i++)frek[i] = 0;
	
	for (int i = 0; i < girdi.size()-1; i++)
		frek[karakterler[i]]++;
	
	// HuffmanAgaci aðacýný oluþtur
	root = AgacOlustur(frek);
	
	// 01 Kodlar oluþturuluyor
	KodOlustur(root, "");
}
/**
 *HuffmanAgaci agacolusturan fonksiyon
 *
 */
HuffmanDugumu* HuffmanAgaci::AgacOlustur(int frek[])
{
	// dosyada var olan karakterler için düðüm oluþtur.
	HuffmanDugumu* HuffmanDugumuler[harfler];
	for(int i=0;i<harfler;i++)
	{
		if(frek[i]>0){
			HuffmanDugumuler[i] = new HuffmanDugumu((char)i,frek[i]);
		}
		else{
			HuffmanDugumuler[i] = NULL;
		}
	}
	while(true)
	{
		int ilkIndeks = MinHuffmanDugumuIndeks(HuffmanDugumuler);				
		HuffmanDugumu *min1 = HuffmanDugumuler[ilkIndeks];
		HuffmanDugumuler[ilkIndeks] = NULL;
		int ikinciIndeks = MinHuffmanDugumuIndeks(HuffmanDugumuler);
		if(ikinciIndeks == -1){
			return min1;
		}
		HuffmanDugumu *min2 = HuffmanDugumuler[ikinciIndeks];
		HuffmanDugumuler[ikinciIndeks] = NULL;
		HuffmanDugumuler[ilkIndeks] = new HuffmanDugumu(0,min1->frekans+min2->frekans,min1,min2);
	}
	
}

int HuffmanAgaci::MinHuffmanDugumuIndeks(HuffmanDugumu* HuffmanDugumuler[]){
	HuffmanDugumu* min;
	int minIndeks=-1;
	
	// ilk null olmayan düðümü min al
	for(int i=0;i<harfler;i++){
		if(HuffmanDugumuler[i] != NULL){
			min = HuffmanDugumuler[i];
			minIndeks = i;
			break;
		}
	}
	
	for(int i=0;i<harfler;i++)
	{
		if(HuffmanDugumuler[i] == NULL) continue;
		
		if(*min > *(HuffmanDugumuler[i])) {
			min = HuffmanDugumuler[i];
			minIndeks = i;
		}
	}
	return minIndeks;
}
/**
 *HuffmanAgaci kod olusturan fonksiyon
 *
 */
void HuffmanAgaci::KodOlustur(HuffmanDugumu* alt_HuffmanDugumu,string kodKarsiligi){
	if(!alt_HuffmanDugumu->isLeaf()){
		KodOlustur(alt_HuffmanDugumu->solDugum,kodKarsiligi+'0');
		KodOlustur(alt_HuffmanDugumu->sagDugum,kodKarsiligi+'1');
	}
	else{
		alt_HuffmanDugumu->kodKarsiligi = kodKarsiligi;
	}
}
/**
 *HuffmanAgaci baslangýc dugumunu donduren fonksiyon
 *
 */
HuffmanDugumu* HuffmanAgaci::Kok()
{
	return root;
}
/**
 *cout operatörünü aþýrý yükleyen fonksiyon
 *
 */
ostream& operator<<(ostream& ekran,HuffmanAgaci& sagDugum){
	ekran<<"HuffmanAgaci Agacindaki Karakterler ve Kodlari:"<<endl;
	sagDugum.inorder(sagDugum.Kok());
	return ekran;
}
/**
 *HuffmanAgaci inorder sýralayan fonksiyon
 */
void HuffmanAgaci::inorder(HuffmanDugumu* alt_HuffmanDugumu){
	if(alt_HuffmanDugumu != NULL)
	{
		inorder(alt_HuffmanDugumu->solDugum);
		if(alt_HuffmanDugumu->isLeaf()) 
		cout<<alt_HuffmanDugumu->karakter<<":"<<alt_HuffmanDugumu->kodKarsiligi<<endl;
		inorder(alt_HuffmanDugumu->sagDugum);
	}
}

void HuffmanAgaci::SilSolHuffmanDugumu(HuffmanDugumu* alt_HuffmanDugumu){
	if(alt_HuffmanDugumu == NULL) return;
	if(alt_HuffmanDugumu->solDugum == NULL) {
		delete alt_HuffmanDugumu;
		alt_HuffmanDugumu = NULL;
		return;
	}	
	SilSolHuffmanDugumu(alt_HuffmanDugumu->solDugum);
}
void HuffmanAgaci::SilSagHuffmanDugumu(HuffmanDugumu* alt_HuffmanDugumu){
	if(alt_HuffmanDugumu == NULL) return;
	if(alt_HuffmanDugumu->sagDugum == NULL) {
		delete alt_HuffmanDugumu;
		alt_HuffmanDugumu = NULL;
		return;
	}	
	SilSolHuffmanDugumu(alt_HuffmanDugumu->sagDugum);
}
HuffmanAgaci::~HuffmanAgaci(){
	// Çöp oluþmamasý için aðaç temizleniyor.
	if(root != NULL){
		SilSolHuffmanDugumu(root->solDugum);
		SilSagHuffmanDugumu(root->sagDugum);
		delete root;
		root = NULL;
	}	
}
HuffmanDugumu* HuffmanAgaci::Dondur(char ch)
{	
	HuffmanDugumu* cr;
	cr=root;
	while(!cr->isLeaf())
	{
		if (cr->karakter == ch)
			return cr;
	}
}
/**
 *HuffmanAgaci dugum arayýp bulduðu düðüm içersindeki char ifadeyi döndüren
 *bu sayede kelimenin her karakteri için bir binary karsilik dondurmemizi saðlayan
 *fonksiyon
 *
 */
string HuffmanAgaci::DugAra(HuffmanDugumu* alt_HuffmanDugumu,char ch)
{
	string drak="";
	if(alt_HuffmanDugumu != NULL)
	{
		DugAra(alt_HuffmanDugumu->solDugum,ch);		
		if(alt_HuffmanDugumu->isLeaf())
		{
			if(alt_HuffmanDugumu->karakter==ch)
			{	
				drak= alt_HuffmanDugumu->kodKarsiligi;
				sonuc=sonuc+drak;				
			}
		}
		
		DugAra(alt_HuffmanDugumu->sagDugum,ch);		
	}
	return sonuc;
}