/**      
 * @file		HeapAgaci.cpp
 * @description	HeapAgaci sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#include "HeapAgaci.hpp"
/**
 *HeapAgaci sınıfının yıkıcı fonksiyonudur.
 *
 */
HeapAgaci::~HeapAgaci()
{
	delete[] dizi;
	dugumSayar = 0;
	this->kapasite = 0;
}
/**
 *Agaca eklenmiş ve küçükten büyüğe sıralanmış ifadeleri
 *diziden çeken fonksiyon
 *
 */
string HeapAgaci::kucuguCikar()
{
	if (bosMu()) cout << "bos";
	string kucuk = dizi[0];
	dizi[0] = dizi[dugumSayar - 1];
	dugumSayar--;
	
	if (dugumSayar > 0) 
		heapAsagi(0);
	return kucuk;
}
/**
 *Agaca ekleme yapan fonksiyon.
 *
 */
void HeapAgaci::Ekle(string word)
{
	if (dugumSayar == kapasite) cout << "tasti";
	dugumSayar++;
	dizi[dugumSayar - 1] = word;
	heapYukari(dugumSayar - 1);
}
/**
 *Gelen yeni değere göre ağaçtaki değerleri asagi taşıyan fonksiyon
 *
 */
void HeapAgaci::heapAsagi(int dugum)
{
	int solCocukIndis, sagCocukIndis, kucuk;
	string temp;
	solCocukIndis = solCocuk(dugum);
	sagCocukIndis = sagCocuk(dugum);

	if (sagCocukIndis >= dugumSayar)
	{
		if (solCocukIndis >= dugumSayar) 
			return;
		else
			kucuk = solCocukIndis;
	}
	else
	{
		if (dizi[solCocukIndis] <= dizi[sagCocukIndis])
			kucuk = solCocukIndis;
		else
			kucuk = sagCocukIndis;
	}
	if (dizi[dugum] > dizi[kucuk])
	{
		temp = dizi[kucuk];
		dizi[kucuk] = dizi[dugum];
		dizi[dugum] = temp;
		heapAsagi(kucuk);
	}
}
/**
 *Gelen yeni değere göre ağaçtaki değerleri yukari taşıyan fonksiyon
 *
 */
void HeapAgaci::heapYukari(int dugum)
{
	int aile_indis;
	string temp;
	if (dugum != 0)
	{
		aile_indis = aile(dugum);
		if (dizi[aile_indis] > dizi[dugum])
		{
			temp = dizi[aile_indis];
			dizi[aile_indis] = dizi[dugum];
			dizi[dugum] = temp;
			heapYukari(aile_indis);
		}
	}
}
/**
 *HeapAgaci sınıfının yıkıcı fonksiyonudur.
 *
 */
bool HeapAgaci::bosMu()
{
	return dugumSayar == 0;
}
/**
 *HeapAgaci sınıfının parametreli kurucu fonksiyonudur.
 *
 */
HeapAgaci::HeapAgaci(int kapasite)
{
	dizi=new string[kapasite];
	dugumSayar=0;
	this->kapasite=kapasite;
}
/**
 *heapAsagi ve heapYukari fonksiyonlarında kullanılmak üzere çalışan
 *fonksiyonlar
 *
 */
int HeapAgaci::aile(int dg)
{
	return (dg - 1) / 2;
}
int HeapAgaci::sagCocuk(int dg)
{
	return 2 * dg + 2;
}
int HeapAgaci::solCocuk(int dg)
{
	return 2 * dg + 1;
}