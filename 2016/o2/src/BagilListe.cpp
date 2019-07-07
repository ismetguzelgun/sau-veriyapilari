/**      
 * @file		BagilListe.cpp
 * @description	BagilListe sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */
#include "BagilListe.hpp"

/**
 *Listenin ilk elemanını dondurur.
 *
 */
Gezici BagilListe::Ilk()
{
	if(DoluMu()) cout<<"Dolu";
	return Gezici(baslamaDugumu);
}
/**
 *Parametresiz kurucu fonksiyon
 *
 */
BagilListe::BagilListe()
{
	this->baslamaDugumu= new Dugum();
	this->elde=0;
	
	//sonDugum=baslamaDugumu;//gezici=baslamaDugumu;
}
/**
 *Parametreli kurucu fonksiyon
 *
 */
BagilListe::BagilListe(int t)
{
	this->baslamaDugumu= new Dugum();
	this->baslamaDugumu->dugumveri=t;
	this->elde=0;
}
/**
 *Listenin başını gösteren simdiki göstericisi NULL ise liste boş demektir
 *Yani daha gidilebilir.
 */
bool BagilListe::DoluMu()
{
	return this->BaslamaDugumuDondur()->ileri==NULL;
}
/**
 *Listedeki eleman sayısını döndermekle sorumlu fonksiyon
 *
 */
int BagilListe::Uzunluk()
{
	Gezici gezici=Ilk();
	int elemansayisi=0;
	for(;!gezici.VardikMi();gezici.Ilerle())
		++elemansayisi;
	return elemansayisi ;
}
/**
 *Belirtilen konumdaki düğümü gösteren düğümü bulan fonksiyon
 *
 */
Gezici BagilListe::DugumuBul(int konum)
{
		int indeks=0;
		Dugum* gezici=BaslamaDugumuDondur();
		while(gezici->ileri != NULL && konum!= indeks++)
			gezici=gezici->ileri;
		return Gezici(gezici);
}
/**
 *Konumu verilen elemanı barındıran düğümü bulan fonksiyon
 *
 */
Gezici BagilListe::OncekiElemaniBul(int konum)
{
	Dugum* gezici=BaslamaDugumuDondur();
	while(gezici->ileri != NULL) 
		if(gezici->ileri->dugumveri==konum)
			return Gezici(gezici);
		//gezici = gezici->ileri;
}
/**
 *Baştaki dugumu silmeye yarayan fonksiyon
 *
 */
void BagilListe::Sil()
{
	Dugum* tmp=new Dugum();
	tmp = this->BaslamaDugumuDondur();
	this->BaslamaDugumuDondur() = this->BaslamaDugumuDondur()->ileri;
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
	Gezici gezici;
	gezici=DugumuBul(konum);
	gezici.simdiki->ileri=new Dugum(yeni,gezici.simdiki->ileri);
}
/**
 *Toplama işleminin sağdan sola doğru yapılabilmesi için listenin terslenmesini sağlayan fonksiyon
 *
 */
BagilListe* BagilListe::Tersle()
{
	Dugum* onceki,*simdiki,*sonraki;
	simdiki=this->BaslamaDugumuDondur();
	onceki=NULL;
	while(simdiki!=NULL)
	{
		sonraki=simdiki->ileri;
		simdiki->ileri=onceki;
		onceki=simdiki;
		simdiki=sonraki;
		
	}
	this->BaslamaDugumuDondur()=onceki;
	onceki=NULL;
	return this;
}

void BagilListe::ListeVeriDondur()
{
		//int st=dd();
	Dugum* d;
	d=this->BaslamaDugumuDondur()->ileri;
	while(!(d==NULL))
	{
			cout<<d->Getir();

			d=d->ileri;	
	}
	d=NULL;
	//bg.ddp();
}
/**
 *(<<) operatörünü aşırı yüklemeye yarayan fonksiyon.
 *
 */
/*ostream& operator<<(ostream& ekran,  BagilListe& bg)
{	
	//int st=dd();
	Dugum* d;
	d=bg.baslamaDugumu->ileri;
	while(!(d==NULL))
	{
			ekran<<d->Getir();
			if(d->ileri!=NULL)
				cout<<"-";
			d=d->ileri;	
	}
	d=NULL;
	//bg.ddp();
	return ekran;
}*/
/**
 *Yıkıcı fonksiyon
 *
 */
BagilListe::~BagilListe()
{
	//delete Sayi;
	Bosalt();
	//delete baslamaDugumu;
}

int BagilListe::UzunlukDondur(int sayi)
{
	uzunluk=sayi;
}

int BagilListe::Uzunlukk()
{
	return uzunluk;
}
Dugum*& BagilListe::BaslamaDugumuDondur()
{
	return baslamaDugumu;
}
/***************/

/**
 *(+) operatorünün aşırı yüklendiği fonksiyon
 *
 */
BagilListe& BagilListe:: operator+(  BagilListe& bg2)
{
	int elde=0;

	int limit=this->Uzunluk();

		/*Y listesi için girilen sayının basamak sayısının Xlistesi için girilen
		**Sayıdan büyük olması durumunda for döngüsü limiti aşacağı için 
		** Kendi limitinin ötesine çıkmak zorunda bırakılacak olan X listesinde
		** bellekten rasgele sayı çevirdiği durumları kısıtlamak gerekti.
		**çekilecek sayının bellek adresinden küçük bir sayi olmasına dikkat edilmek koşuluyla
		**eğer limit aşılmışsa küçük basamaklı sayının eksik hanesi işleme tabi tutulmadı.*/
	for(int i=0;i<limit-1;i++)
	{
		//cout<<"i: "<<i<<" limit:  "<<limit<<endl;
		if(bg2.DugumuBul(i).Getir()<100)
		{
			this->DugumuBul(i).Getir()=((this->DugumuBul(i).Getir()+bg2.DugumuBul(i).Getir()+elde));
			//cout<<"elde eklemeden sonra (bg2): "<<bg2.DugumuBul(i).Getir()<<"   "<<"elde eklemeden sonra (this): "<<this->DugumuBul(i).Getir()<<"   elde: "<<elde<<endl;
			elde=this->DugumuBul(i).Getir()/10;
			//cout<<"elde hesapladiktan sonra (bg2): "<<bg2.DugumuBul(i).Getir()<<"   "<<"elde hesapladiktan sonra (this): "<<this->DugumuBul(i).Getir()<<"   elde: "<<elde<<endl;
			this->DugumuBul(i).Getir()=this->DugumuBul(i).Getir()%10;
			this->elde=elde;
		}
		else
		{
			this->DugumuBul(i).Getir()=((this->DugumuBul(i).Getir()+elde));
			//cout<<"elde eklemeden sonra else (bg2): "<<bg2.DugumuBul(i).Getir()<<"   "<<"elde eklemeden sonra (this): "<<this->DugumuBul(i).Getir()<<"   elde: "<<elde<<endl;
			elde=this->DugumuBul(i).Getir()/10;
			//cout<<"elde hesapladiktan sonra else (bg2): "<<bg2.DugumuBul(i).Getir()<<"   "<<"elde hesapladiktan sonra (this): "<<this->DugumuBul(i).Getir()<<"   elde: "<<elde<<endl;
			this->DugumuBul(i).Getir()=this->DugumuBul(i).Getir()%10;
			this->elde=elde;
		}

	}
	if(this->elde>0)
		this->Ekle(elde,limit-2);
	return *this;
}