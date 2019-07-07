/**      
 * @file		UlkeDugum.cpp
 * @description	UlkeDugum sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */

#include "UlkeDugum.hpp"
/**
 *UlkeDugum sınıfının kurucu fonksiyonudur.
 *
 */
UlkeDugum::UlkeDugum()
{
	sol=NULL;
	sag=NULL;
	data="";
	sh=new Sehir();
}
/**
 *UlkeDugum sınıfının parametreli kurucu fonksiyonudur.
 *
 */
UlkeDugum::UlkeDugum(string dt)
{
	sol=NULL;
	sag=NULL;
	data=dt;
	sh=new Sehir();
}
/**
 *agacDondur fonksiyonu ile aldığı string ifadeyi heap agacina ekleyen fonksiyon
 *
 */
void UlkeDugum::sehirDondur(string dg2)
{
	return sh->agacDondur(dg2);
}
/**
 *Heap agacina yerleştirilmiş şehirlere içerisindeki şehir nesnesinin
 *fonksiyonu ile erişip bunları Ulke sınıfına getirmek için yazılmış fonksiyon
 *
 */
void UlkeDugum::yazmakIcinSehirGetir()
{
	return sh->Yaz();
}/**
 *UlkeDugum sınıfının yıkıcı fonksiyonudur.
 *
 */
UlkeDugum::~UlkeDugum()
{
	delete sh;
}