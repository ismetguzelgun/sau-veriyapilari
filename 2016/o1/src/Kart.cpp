/**
 * @file		Kart.cpp
 * @description	Kart sınıfı için gerekli üye fonksiyonları içeren kaynak dosyası
 * @course		II-A
 * @assignment 	1
 * @date		19.10.2016
 * @author		
 *
 *
 */
#include "Kart.hpp"
//parametreli kurucu fonksiyon
Kart::Kart(int sayi)
{
	this->kartNo=sayi;
	semboller=new Sembol();

	this->randTip=semboller->SembolTipiDondur()=rand()%4;
	this->randRenk=semboller->SembolRenkDondur()=rand()%16;

}
//kart sınıfının üye değişkeni olan semboller için
//random olarak sembol ve renk belirlememizi sağlayan
//uretici fonksiyon
string Kart::KartUreteci()
{
	kartSembol=semboller->SembolBelirle(randTip,randRenk);
	return kartSembol;
}
//kart sınıfı parametresiz kurucu fonksiyonu
Kart::Kart()
{
	this->kartNo=0;
}

//kart sınıfı yıkıcı fonksiyonu
Kart::~Kart()
{
	delete semboller;
}
//Simgeleri renklerindiren fonksiyonun
//kullanımından sonra SembolRenkResetle
//fonksiyonunun çağrılmasına ihtiiyaç vardır
//aksi halde oluşturulan simgeden sonraki simgeler
//aynı renkte devam etmektedirler.
void Kart::Reset()
{
	semboller->SembolRenkResetle();
}
Sembol*& Kart::KartIcinSembolDondur()
{
	return semboller;
}
//private olarak tanımlanan kartNo
//değişkenine erişmek için kullanılan metod
int& Kart::KartNumarasiDondur()
{
	return kartNo;
}
//----------------------------------------------------
//Nesneler heap bellek bölgesinde oluşturulabilinmiş mi
//kontrol amacıyla yazdığım bir fonksiyon
//istenirse aktif edilebilir
/*
void Kart::KartIcinSembolAdresiDondur()
{
	cout<<&semboller<<"                   ";
}*/

