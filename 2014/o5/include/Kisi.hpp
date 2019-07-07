/**
* @file			Kisi.hpp
* @description 	Kisi sınıfını tanımlayan hpp dosyası
* @course		1-B
* @assignment	5
* @date			12.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*				İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/

#ifndef KISI_HPP
#define KISI_HPP
#include "HuffmanAgaci.hpp"
class Kisi
{
public:
	string kisiDondur();
	Kisi(string);
	Kisi();
	~Kisi();
private:
	string kisi;

};
#endif