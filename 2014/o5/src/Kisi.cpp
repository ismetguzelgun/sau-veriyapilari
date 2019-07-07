/**
* @file 		Kisi.cpp
* @description	Kisi sınıfından nesne oluşturup diğer sınıflara veren cpp dosyası
* @course		1-B
* @assignment 	5
* @date 		12.12.2014
* @author 		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*		  		İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#include "Kisi.hpp"
/**
 *Kisi kurucusu
 *
 */
Kisi::Kisi(string _ks)
{
	kisi=_ks;
}
/**
 *Kisi kurucusu
 *
 */
Kisi::Kisi()
{

}
/**
 *kisi verisini donduren fonksiyon
 *
 */
string Kisi::kisiDondur()
{
	return kisi;
}
/**
 *Kisi yıkıcısı
 *
 */
Kisi::~Kisi()
{
}