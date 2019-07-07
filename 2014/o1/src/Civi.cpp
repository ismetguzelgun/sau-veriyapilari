/**      
 * @file		Civi.cpp
 * @description	Civi sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	1	
 * @date		20.09.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *
 */
 
#include "Civi.hpp"

/**
 *Civi sınıfının kurucu fonksiyonudur.
 *
 */
Civi::Civi(int i)
{
	sepet= new Sepet(i);
	civiNo=i;
}

/**
 *Civi sınıfının yıkıcı fonksiyonudur.
 *
 */
Civi::~Civi()
{
	delete sepet;
}

/**
 *Civi sınıfının kurucusunda oluşturduğumuz sepet nesnesinin
 *SepetCiz() fonksiyonunu çağıran fonksiyon
 *
 */
void Civi::CiviYazdir()
{
	sepet->SepetCiz();
	cout<<&sepet<<endl<<endl;
}

/**
 *Bu fonksiyonun varlığı civileri ve sepetleri ekrana yazdırırken
 *yaşadığımız çok önemli bir sorunu çözmekte kullanılmak üzere
 *SepetKontrol sınıfında oluşturulan civi nesnelerinin kullanımına
 *sunulacaktır.
 *
 */
char Civi::CiviyeSepetAdiDondur()
{
	sepet->SepetAdiDondur();
}
