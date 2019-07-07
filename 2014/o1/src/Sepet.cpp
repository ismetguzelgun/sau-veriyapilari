/**      
 * @file		Sepet.cpp
 * @description	Sepet sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	1	
 * @date		20.09.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *
 */

#include "Sepet.hpp"

/**
 *Sepet sınıfının kurucu fonksiyonudur.
 *
 */
Sepet::Sepet(int i)
{
	sepNo=i;
}

/**
 *Sepet sınıfının kurucusundan döndürülen sepet numarasına göre
 *SepetCiz() fonksiyonunun hangi harfi yazdıracağını ayarlayan
 *fonksiyon.
 *
 */
char Sepet::SepetAdiBelirle(int n)
{
	switch(n)
	{
		case '0':
		{
			sepAd='A';
			return 0;
		}
		case 1:
		{
			sepAd='B';
			return sepAd;
		}
		case 2:
		{
			sepAd='C';
			return sepAd;	
		}
	}
}

/**
 *Civi sınıfına A,B ya da C olarak belirlenmiş sepet adını dondurmek
 *için tasarlanmış fonksiyondur.
 *
 */
char Sepet::SepetAdiDondur()
{
	return SepetAdiBelirle(sepNo);
}

/**
 *Sepet şeklini çizen fonksiyon.SepetAdiBelirle() fonksiyonunu
 *içererek sepet çizdirildiği sırada harfinide yazar.
 *
 */
void Sepet::SepetCiz()
{
	cout		<<	"  .|.  "<<endl<<" .   . "<<endl<<".     ."<<endl<<"#     #"<<endl<<"#  "<<SepetAdiBelirle(sepNo)<<"  #"<<endl<<"#     #"<<endl<<"#######\n";
}
