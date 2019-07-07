/**
* @file			HashDugum.hpp
* @description 	HashDugum sınıfını tanımlayan hpp dosyası
* @course		1-B
* @assignment	5
* @date			12.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*				İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#ifndef HASHDUGUM_HPP
#define HASHDUGUM_HPP
#include "Kisi.hpp"
class HashDugum
{
public:
	//int hashDeger;
	string veri;
	Kisi* kisi;
	HashDugum* sonraki;
	HashDugum(Kisi* );
	HashDugum(Kisi* ,HashDugum*);
	//HashDugum(HashDugum*,Kisi*);
	
	void kisiDondurDosyaOkusun(string);
	void kisiDondurKodlasin();

};
#endif