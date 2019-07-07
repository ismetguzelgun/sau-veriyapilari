#include "Sayi.hpp"
Sayi::Sayi()
{
	sayiListesi=new BagilListe();
}
Sayi::~Sayi()
{
	delete sayiListesi;
}
ostream& operator<<(ostream& ekran,  Sayi& bg)
{
	Dugum* d;
	d=bg.SayiListesiDondur()->BaslamaDugumuDondur()->ileri;
	while(!(d==NULL))
	{
			ekran<<d->Getir();
			if(d->ileri!=NULL)
				cout<<"-";
			d=d->ileri;	
	}
	d=NULL;
	return ekran;
}

BagilListe*& Sayi::SayiListesiDondur()
{
	return sayiListesi;
}
Sayi& Sayi::operator +(  Sayi& bg2 )
{

	*this->sayiListesi=*(this->sayiListesi)+*(bg2.sayiListesi);
	return *this;

}
void Sayi::ToplamiYaz()
{
	Dugum* d;
	d=this->SayiListesiDondur()->BaslamaDugumuDondur()->ileri;
	while(!(d==NULL))
	{
			cout<<d->Getir();

			d=d->ileri;	
	}
	d=NULL;
}