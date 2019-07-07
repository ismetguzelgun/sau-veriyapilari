/**      
 * @file		Sehir.cpp
 * @description	Sehir sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#include "Sehir.hpp"
/**
 *Sehir sınıfının kurucu fonksiyonudur.
 *
 */
Sehir::Sehir()
{
	hp= new HeapAgaci(100);
}
/**
 *HeapAgacina eklenmiş şehirleri yazdıran fonksiyon.
 *Bu fonksiyonu inOrderSirala() fonksiyonu içerisinde kullaniyoruz
 */
void Sehir::Yaz()
{
	while (!hp->bosMu())
		cout << hp->kucuguCikar() << " ";
}
/**
 *Ulke sınıfında heapagacina deger ekleyebilmek icin
 *çalıştırdığımız fonksiyon.
 *
 */
void Sehir::agacDondur(string dg2)
{
	return hp->Ekle(dg2);
}
/**
 *Ulke sınıfının yıkıcı fonksiyonudur.
 *
 */
Sehir::~Sehir()
{
	delete hp;
}