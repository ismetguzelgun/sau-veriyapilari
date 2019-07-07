/**      
 * @file		Sehir.hpp
 * @description	Sehir sınıfına ait kütüphane
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#ifndef Sehir_HPP
#define Sehir_HPP
#include "HeapAgaci.hpp"
class Sehir
{
public:
	Sehir();
	void Yaz();
	void agacDondur(string);
	~Sehir();
private:
	HeapAgaci* hp;
};
#endif