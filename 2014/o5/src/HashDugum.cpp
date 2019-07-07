/**
* @file			HashDugum.cpp
* @description	HashDugum oluşturan cpp dosyası
* @course		1-B
* @assignment	5
* @date			15.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*				İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#include "HashDugum.hpp"
/**
 *HashDugum kurucu fonksiyonu
 *
 */
HashDugum::HashDugum(Kisi* ks)
{
	kisi=ks;
	sonraki=NULL;
	veri=kisi->kisiDondur();

}
/**
 *HashDugum kurucu fonksiyonu
 *
 */
HashDugum::HashDugum(Kisi* ks,HashDugum* hs=NULL)
{
	sonraki=hs;
	kisi=ks;
	veri=kisi->kisiDondur();
}
