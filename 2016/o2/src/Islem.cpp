/**      
 * @file		Islem.cpp
 * @description	Islem sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
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
	YokEt();
	/*
	delete sayi1;
	delete sayi2;
//	delete sayi3;*/
}
/**
 *string olarak aldırılan sayıları integer cinsine çevirmek için kullandığımız switch yapısını içeren 
 *fonksiyon.
 *
 */
int Islem::KarakterdenSayiyaDondur(char cs)
{
	int sayi=(int) cs-48;
	return sayi;
}

/**
 *Her liste için ayrı ayrı yazmak durumunda kaldığımız ilk listeye dugum ekleyen fonksiyon
 *
 */
void Islem::ilkListeYarat(string s)
{
	sayi1=new Sayi();

	for(int i=0;i<s.length();i++)
	{
		sayi1->SayiListesiDondur()->Ekle(KarakterdenSayiyaDondur(s[i]),i);
	}
	
	cout<<"x listesi :"<<*sayi1<<endl;
}
/**
 *ikinci listeye dugum ekleyen fonksiyon
 *
 */
void Islem::ikinciListeYarat(string s)
{

	sayi2=new Sayi();

	for(int i=0;i<s.length();i++)
	{
		sayi2->SayiListesiDondur()->Ekle(KarakterdenSayiyaDondur(s[i]),i);
	}
	
	cout<<"y listesi :"<<*(sayi2)<<endl;
}
/**
 *Toplama işlemini gerçekleştirdiğimiz fonksiyon
 *
 */
void Islem::Topla()
{
	sayi3= new Sayi();
	
	sayi1->SayiListesiDondur()->Tersle();
	sayi2->SayiListesiDondur()->Tersle();
	BagilListe* temp=new BagilListe();

	if(sayi1->SayiListesiDondur()->Uzunluk()<=sayi2->SayiListesiDondur()->Uzunluk())
	{
		
		temp=sayi1->SayiListesiDondur();
		sayi1->SayiListesiDondur()=sayi2->SayiListesiDondur();
		sayi2->SayiListesiDondur()=temp;
		/*cout<<"y listesi :"<<*(sayi2)<<endl;
		cout<<"y listesi :"<<*(sayi1)<<endl;*/
		*sayi3=(*sayi1+ *sayi2);
		
	}
	else
		*sayi3=(*sayi1+ *sayi2);
	
	sayi3->SayiListesiDondur()->Tersle();
	//string st=(*liste3);
	cout<<"x+y: ";
	sayi3->ToplamiYaz();
	//liste3->ListeVeriDondur();
	delete temp;
}
void Islem::YokEt()
{

delete sayi1;

}