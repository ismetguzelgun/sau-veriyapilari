/**
* @file			HuffmanAgaci.hpp
* @description 	HuffmanAgaci sınıfını tanımlayan hpp dosyası
* @course		1-B
* @assignment	5
* @date			12.12.2014
* @author		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*				İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#ifndef HUFFMANAGACI__HPP
#define HUFFMANAGACI__HPP
#include "HuffmanDugumu.hpp"

class HuffmanAgaci
{
private:
	int harfler;  			
	string girdi;			
	HuffmanDugumu *root;
	HuffmanDugumu* AgacOlustur(int frek[]);
	int MinHuffmanDugumuIndeks(HuffmanDugumu* HuffmanDugumuler[]);
	void inorder(HuffmanDugumu*);
	void SilSolHuffmanDugumu(HuffmanDugumu*);
	void SilSagHuffmanDugumu(HuffmanDugumu*);
public:
	HuffmanDugumu* Kok();
	string sonuc;
	void KodOlustur(HuffmanDugumu*,string);
	string DugAra(HuffmanDugumu*,char);
	HuffmanAgaci();
	void Kodla();
	void DosyaOku(string);
	HuffmanDugumu* Dondur(char);
	friend ostream& operator<<(ostream&,HuffmanAgaci&);
	~HuffmanAgaci();
};
#endif