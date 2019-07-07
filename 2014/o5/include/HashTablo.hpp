/**
* @file			HashTablo.hpp
* @description 	HashTablo sınıfını tanımlayan hpp dosyası
* @course		1-B
* @assignment	5
* @date			12.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*				İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#ifndef HASHTABLO_HPP
#define HASHTABLO_HPP
#define MAKSIMUM 101
#include "HashDugum.hpp"
class HashTablo
{
public:
	HashTablo();
	~HashTablo();
	void agacDondurDosyaOku(string);
	void agacDondurKodla();
//private:
	void hesaplaVeEkle(string);
	string binarySayi;
	int desimalSayi;
	int desimalHesapla(string);
	HashDugum* gecici;
	HuffmanAgaci* agac;
	HashDugum* Dizi[MAKSIMUM];

	int HashKodu( int);
	void Ekle(string, int);
	void Temizle();
	bool Bul(string,int);
	bool isEmpty();
	void Yaz();
};
#endif