/**      
 * @file		Islem.cpp
 * @description	Islem sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	2	
 * @date		22.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */
#include "Islem.hpp"
/**
 *Parametresiz kurucu Islem fonksiyonu
 *
 */
Islem::Islem()
{

}
/**
 *Yıkıcı fonksiyon
 *
 */
Islem::~Islem()
{
	delete liste1;
	delete liste2;
	delete liste3;
}
/**
 *string olarak aldırılan sayıları integer cinsine çevirmek için kullandığımız switch yapısını içeren 
 *fonksiyon.
 *
 */
int Islem::KarakterdenSayiyaDondur(char cs)
{
	switch (cs)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case'8':
			return 8;
		case '9':
			return 9;
		case '\0':
			return 0;
	}
}

/**
 *Her liste için ayrı ayrı yazmak durumunda kaldığımız ilk listeye dugum ekleyen fonksiyon
 *
 */
void Islem::ilkListeYarat(string s)
{
	liste1=new BagilListe();
	liste1->UzunlukDonder(s.length());
	for(int i=0;i<s.length();i++)
	{
		liste1->Ekle(KarakterdenSayiyaDondur(s[i]),i);
	}
	
	cout<<"x listesi :"<<*liste1<<endl;
}
/**
 *ikinci listeye dugum ekleyen fonksiyon
 *
 */
void Islem::ikinciListeYarat(string s)
{

	liste2=new BagilListe();
	liste2->UzunlukDonder(s.length());
	for(int i=0;i<s.length();i++)
	{
		liste2->Ekle(KarakterdenSayiyaDondur(s[i]),i);
	}
	
	cout<<"y listesi :"<<*(liste2)<<endl;
}
/**
 *Toplama işlemini gerçekleştirdiğimiz fonksiyon
 *
 */
void Islem::Topla()
{
	liste3= new BagilListe();

	
	if(liste2->Uzunluk()<=liste1->Uzunluk())
	{
		liste1->Tersle(liste1);
		liste2->Tersle(liste2);
		liste3=&(*liste1+ *liste2);
	}
	else
	{
		liste1->Tersle(liste1);
		liste2->Tersle(liste2);
		liste3=&(*liste2+ *liste1);
	}
	liste3->Tersle(liste3);
	cout<<"x+y: "<<*liste3;
}