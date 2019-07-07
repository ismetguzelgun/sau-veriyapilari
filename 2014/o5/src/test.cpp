/**
* @file 		test.cpp
* @description 	Program cpp dosyası
* @course 		1-B
* @assignment 	5
* @date 		18.12.2014
* @author 		İsmet GÜZELGÜN b121210025@sakarya.edu.tr
*		  		İbrahim AKDAĞ  b121210027@sakarya.edu.tr		  
*/
#include "HashTablo.hpp"
int main()
{
	HashTablo* ht = new HashTablo();
	string _sonuc="";
	string _girdi="";
	ifstream dosya;
	dosya.open ("bilgi.txt");
	
	if (dosya.is_open())
	{
		while (getline(dosya,_sonuc))
		{
			_girdi+=_sonuc;
			_girdi+='\n';
		}
		dosya.close();
	}
	ht->agacDondurDosyaOku(_girdi);
	ht->agacDondurKodla();

	
	ifstream dosya2;
	dosya2.open ("bilgi.txt");
	int i = 0;
	if (dosya2.is_open())
	{
		while (getline(dosya2,_sonuc))
		{

			_girdi+=_sonuc;
			_girdi+='\n';
			ht->hesaplaVeEkle(_sonuc);
		}
		dosya2.close();
	}
	ht->Yaz();
	delete ht;
	return 0;
}