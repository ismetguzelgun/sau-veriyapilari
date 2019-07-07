/**      
 * @file		HeapAgaci.hpp
 * @description	HeapAgaci sınıfına ait kütüphane
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */

#ifndef HeapAgaci_HPP
#define HeapAgaci_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
class HeapAgaci
{
public:
	void Ekle(string );
	string kucuguCikar();
	bool bosMu();
	~HeapAgaci();
	HeapAgaci(int );
	
private:
	string* dizi;
	int dugumSayar;
	int kapasite;
	int solCocuk(int );
	int sagCocuk(int );
	int aile(int );
	void heapYukari(int );
	void heapAsagi(int );
	
};
#endif