/**
* @file			HashTablo.cpp
* @description	HashTablo oluşturan cpp dosyası
* @course		1-B
* @assignment	5
* @date			15.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*				İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#include "HashTablo.hpp"
/**
 *HashTablo kurucusu
 *
 */
HashTablo::HashTablo()
{
	for(int i=0;i<MAKSIMUM;i++)
		Dizi[i] = NULL;
	agac=new HuffmanAgaci();
	binarySayi="";
	desimalSayi=0;
}
/**
 *HashTablo binary string ifadeyi desimale çeviren fonksiyon
 *
 */
int HashTablo::desimalHesapla(string s)
{
	int i,sum = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		sum = (sum << 1) + s[i] - '0';
	}
	if(sum<0)
		return sum*-1;
	//cout<<sum;
	return sum;

}
void HashTablo::agacDondurDosyaOku(string st)
{
	return agac->DosyaOku(st);
}
void HashTablo::agacDondurKodla()
{
	return agac->Kodla();
}
/**
 *HashTablo binary string ifadeyi desimale çeviren fonksiyon
 *
 */
void HashTablo::hesaplaVeEkle(string st)
{
	int ddesimalSayi=0;
	string bbinarySayi="";
	HuffmanDugumu* hd=agac->Kok();
	for(int i=0;i<st.length();i++)
		agac->DugAra(hd,st[i]);
	bbinarySayi=agac->sonuc;
	agac->sonuc="";
	ddesimalSayi=desimalHesapla(bbinarySayi);
	Ekle(st,ddesimalSayi);
	
}
/**
 *HashTablo ekle fonksiyonu
 *
 */
void HashTablo::Ekle(string isim,int sayi)
{

	if(Bul(isim,sayi)) 
		return;
	int indeks = HashKodu(sayi);
	Dizi[indeks] = new HashDugum(new Kisi(isim),Dizi[indeks]);
}
/**
 *HashTablo bulan fonksiyon
 *
 */
bool HashTablo::Bul(string isim,int sayi) 
{
	int indeks = HashKodu(sayi);
	HashDugum *tmp = Dizi[indeks];
	while(tmp != NULL)
	{
		if(tmp->veri == isim)return true;
		tmp=tmp->sonraki;
	}
	return false;
}
/**
 *HashTablo gidilecek yer dolu mu bos mu kontrol eden fonksiyon
 *
 */
bool HashTablo::isEmpty() 
{
	for(int i=0;i<MAKSIMUM;i++){
		if(Dizi[i] != NULL) return false;
	}
	return true;
}
/**
 *HashTablo mod alarak hashkodu oluşturan fonksiyon
 *
 */
int HashTablo::HashKodu(int sayi)
{

	return sayi%100;
}
/**
 *HashTablo yıkıcı fonksiyona yardımcı olan fonksiyon
 *
 */
void HashTablo::Temizle()
{
	for(int i=0;i<MAKSIMUM;i++)
	{
		HashDugum *tmp = Dizi[i];
		while(tmp != NULL)
		{
			HashDugum* sil = tmp;
			tmp=tmp->sonraki;
			delete sil;
		}
		Dizi[i] = NULL;
	}
}
/**
 *HashTablo yıkıcı fonksiyon
 *
 */
HashTablo::~HashTablo()
{
	Temizle();
}
/**
 *HashTablo yazdırma fonksiyonu
 *
 */
void HashTablo::Yaz()
{
	for(int i=0;i<MAKSIMUM;i++)
	{
		if(Dizi[i] != NULL)
		{
			cout<<"Hash["<<i<<"]=";
			for(HashDugum *tmp = Dizi[i];tmp != NULL;tmp=tmp->sonraki)
			{
				cout<<tmp->veri<<"->";
			}
			cout<<"NULL"<<endl;
		}
	}
}