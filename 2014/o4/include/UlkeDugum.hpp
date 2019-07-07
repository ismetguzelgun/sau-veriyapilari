/**      
 * @file		UlkeDugum.hpp
 * @description	UlkeDugum sınıfına ait kütüphane
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#ifndef UlkeDugum_HPP
#define UlkeDugum_HPP
#include "Sehir.hpp"
#include "Dugum.hpp"
class UlkeDugum:Dugum
{
public:
	UlkeDugum* sol;
	UlkeDugum* sag;
	void sehirDondur(string);
	void yazmakIcinSehirGetir();
	string data;
	UlkeDugum(string);
	UlkeDugum();
	~UlkeDugum();
private:
	Sehir* sh;

};
#endif