/**
* @file 		HuffmanAgaci.cpp
* @description 	HuffmanAgaci olu�turan cpp dosyas�
* @course		1-B
* @assignment	5
* @date			15.12.2014
* @author		�smet G�ZELG�N b121210025@sakarya.edu.tr
*		 		�brahim AKDA�  b121210027@sakarya.edu.tr		  
*/
#include "HuffmanAgaci.hpp"
/**
 *HuffmanAgaci y�k�c�s�
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
	
	//Frekanslar� say
	int frek[harfler]; 
	// frekanslar� s�f�rla
	for(int i=0;i<harfler;i++)frek[i] = 0;
	
	for (int i = 0; i < girdi.size()-1; i++)
		frek[karakterler[i]]++;
	
	// HuffmanAgaci a�ac�n� olu�tur
	root = AgacOlustur(frek);
	
	// 01 Kodlar olu�turuluyor
	KodOlustur(root, "");
}
/**
 *HuffmanAgaci agacolusturan fonksiyon
 *
 */
HuffmanDugumu* HuffmanAgaci::AgacOlustur(int frek[])
{
	// dosyada var olan karakterler i�in d���m olu�tur.
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
	
	// ilk null olmayan d���m� min al
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
 *HuffmanAgaci baslang�c dugumunu donduren fonksiyon
 *
 */
HuffmanDugumu* HuffmanAgaci::Kok()
{
	return root;
}
/**
 *cout operat�r�n� a��r� y�kleyen fonksiyon
 *
 */
ostream& operator<<(ostream& ekran,HuffmanAgaci& sagDugum){
	ekran<<"HuffmanAgaci Agacindaki Karakterler ve Kodlari:"<<endl;
	sagDugum.inorder(sagDugum.Kok());
	return ekran;
}
/**
 *HuffmanAgaci inorder s�ralayan fonksiyon
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
	// ��p olu�mamas� i�in a�a� temizleniyor.
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
 *HuffmanAgaci dugum aray�p buldu�u d���m i�ersindeki char ifadeyi d�nd�ren
 *bu sayede kelimenin her karakteri i�in bir binary karsilik dondurmemizi sa�layan
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