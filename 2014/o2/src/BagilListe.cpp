/**      
 * @file		BagilListe.cpp
 * @description	BagilListe sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */
#include "BagilListe.hpp"

/**
 *Listenin ilk elemanını dondurur.
 *
 */
Sayi BagilListe::Ilk()
{
	if(DoluMu()) cout<<"Dolu";
	return Sayi(baslamaDugumu);
}
/**
 *Parametresiz kurucu fonksiyon
 *
 */
BagilListe::BagilListe()
{
	baslamaDugumu= new Dugum();
	//sonDugum=baslamaDugumu;//gezici=baslamaDugumu;
}
/**
 *Parametreli kurucu fonksiyon
 *
 */
BagilListe::BagilListe(int t)
{
	baslamaDugumu= new Dugum();
	baslamaDugumu->dugumveri=t;
}
/**
 *Listenin başını gösteren simdiki göstericisi NULL ise liste boş demektir
 *Yani daha gidilebilir.
 */
bool BagilListe::DoluMu()
{
	return baslamaDugumu->ileri==NULL;
}
/**
 *Listedeki eleman sayısını döndermekle sorumlu fonksiyon
 *
 */
int BagilListe::Uzunluk()
{
	Sayi gezici=Ilk();
	int elemansayisi=0;
	for(;!gezici.VardikMi();gezici.Ilerle())
		elemansayisi++;
	return elemansayisi ;
}
/**
 *Belirtilen konumdaki düğümü gösteren düğümü bulan fonksiyon
 *
 */
Sayi BagilListe::DugumuBul(int konum)
{
		int indeks=0;
		Dugum* gezici=baslamaDugumu;
		while(gezici->ileri != NULL && konum!= indeks++)
			gezici=gezici->ileri;
		return Sayi(gezici);
}
/**
 *Konumu verilen elemanı barındıran düğümü bulan fonksiyon
 *
 */
Sayi BagilListe::OncekiElemaniBul(int konum)
{
	Dugum* gezici=baslamaDugumu;
	while(gezici->ileri != NULL) 
		if(gezici->ileri->dugumveri==konum)
			return Sayi(gezici);
		//gezici = gezici->ileri;
}
/**
 *Baştaki dugumu silmeye yarayan fonksiyon
 *
 */
void BagilListe::Sil()
{
	Dugum* tmp = baslamaDugumu;
	baslamaDugumu = baslamaDugumu->ileri;
	delete tmp;

	/*
	Sayi sy=OncekiElemaniBul(konum);
	if(sy.simdiki->ileri->ileri !=NULL)
	{
		Dugum* onceki=sy.simdiki->ileri;
		sy.simdiki->ileri= sy.simdiki->ileri->ileri;
		delete onceki;
	}*/
}
/**
 *Tum dugumleri belleğe geri veren fonksiyon
 *
 */
void BagilListe::Bosalt()
{
	while(!DoluMu())
		Sil();
}

/**
 *Verilen elemanı sona ekler
 *
 */
void BagilListe::Ekle(int yeni)
{
	Ekle(yeni,Uzunluk());
}
/**
 *Verilen elemanı verilen konuma ekler
 *
 */
void BagilListe::Ekle(int yeni,int konum)
{
	//konum=konum/2;
	Sayi gezici;
	gezici=DugumuBul(konum);
	gezici.simdiki->ileri=new Dugum(yeni,gezici.simdiki->ileri);
}
/**
 *Toplama işleminin sağdan sola doğru yapılabilmesi için listenin terslenmesini sağlayan fonksiyon
 *
 */
BagilListe* BagilListe::Tersle(BagilListe* bg)
{
	Dugum* onceki,*simdiki,*sonraki;
	simdiki=bg->baslamaDugumu;
	onceki=NULL;
	while(simdiki!=NULL)
	{
		sonraki=simdiki->ileri;
		simdiki->ileri=onceki;
		onceki=simdiki;
		simdiki=sonraki;
		
	}
	bg->baslamaDugumu=onceki;
	onceki=NULL;
	return bg;
}
/**
 *(+) operatorünün aşırı yüklendiği fonksiyon
 *
 */
BagilListe& BagilListe:: operator+(  BagilListe& bg2)
{

	BagilListe temp=*this;
	Sayi gezici=bg2.Ilk();
	Sayi gezici2=this->Ilk();
	Sayi gezici3=temp.Ilk();
	int elde=0;

	for(;!gezici.VardikMi()&&!gezici3.VardikMi();gezici.Ilerle())
	{
		
		gezici2.Getir()=((gezici3.Getir()+gezici.Getir()+elde));
		elde=gezici2.Getir()/10;
		gezici3.Getir()=gezici2.Getir()%10;

		//elde=gezici2.Getir()/10;
		gezici3.simdiki=gezici3.simdiki->ileri;
		gezici2.simdiki=gezici2.simdiki->ileri;	
	
		
	}
	
	if(elde)
	{
		//this->Ekle(elde);
		//*this=temp;
		//temp=NULL;
		//gezici3.simdiki=gezici3.simdiki->ileri;
		//gezici2.simdiki=gezici2.simdiki->ileri;		
		/*Dugum* yeniDugum=new Dugum(elde,gezici2.simdiki);
		gezici2.simdiki->ileri=yeniDugum;
		gezici3.simdiki=yeniDugum;
		yeniDugum->dugumveri=elde;*/
	}
		
	return *this;
}

/**
 *(<<) operatörünü aşırı yüklemeye yarayan fonksiyon.
 *
 */
ostream& operator<<(ostream& ekran,  BagilListe& bg)
{	

	Dugum* d;
	d=bg.baslamaDugumu->ileri;
	while(!(d==NULL))
	{
			ekran<<d->Getir();
			d=d->ileri;	
	}
	d=NULL;

	return ekran;
}
/**
 *Yıkıcı fonksiyon
 *
 */
BagilListe::~BagilListe()
{
	//delete Sayi;
	//Bosalt();
	//delete baslamaDugumu;
}

int BagilListe::UzunlukDonder(int sayi)
{
	uzunluk=sayi;
}

int BagilListe::Uz()
{
	return uzunluk;
}
