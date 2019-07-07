/**      
 * @file		SepetKontrol.cpp
 * @description	SepetKontrol sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	1	
 * @date		21.09.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 */

#include "SepetKontrol.hpp"

/**
 *SepetKontrol sınıfının kurucu fonksiyonudur.
 *
 */
SepetKontrol::SepetKontrol()
{
	for(int i=0;i<3;i++)
		civiler[i]=new Civi(i);
}

/**
 *SepetKontrol sınıfının yıkıcı fonksiyonudur.
 *
 */
SepetKontrol::~SepetKontrol()
{
	for(int i=0;i<3;i++)
		delete civiler[i];
}

/**
 *Ekrana çivileri yazdıran ,civiler[] dizisi yardımıyla Sepet sınıfındaki
 *SepetCiz() fonksiyonuna ulaşan fonksiyondur.
 *
 */
void SepetKontrol::Yazdir()
{
	for(int i=0;i<3;i++)
	{
		civiler[i]->CiviYazdir();
		//cout<<&civiler[i]<<endl;
	}
}

/**
 *Hangi sepetlerin değiştirileceği belirlendikten sonra
 *çivilere asılı sepetleri değiştirmek için kullanılan fonksiyondur.
 *
 */
void SepetKontrol::Degistir(int hedef,int kaynak)
{
	pcivi=civiler[hedef];
	civiler[hedef]=civiler[kaynak];
	civiler[kaynak]=pcivi;
}

/**
 *Bu fonksiyon aldığı char değere göre integer bir değer döndürerek aldığı 
 *değerin hedef ya da kaynak olarak aldığı değerin o an dizinin hangi elemanına 
 *ait olduğunu saptar.Sınıfın olmazsa olmaz üye fonksiyonudur.
 *
 */
int SepetKontrol::DogruIndexiDondur(char dogruMu)
{
	for(int i=0;i<3;i++)
	{
		if(civiler[i]->CiviyeSepetAdiDondur()==dogruMu)
			return i;
	}
}