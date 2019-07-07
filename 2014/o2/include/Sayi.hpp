/**      
 * @file		Sayi.hpp
 * @description	Sayi sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */
 
#ifndef SAYI_HPP
#define	SAYI_HPP
#include "Dugum.hpp"
class Sayi
{
	public:
		Sayi();
		Sayi(Dugum*);
		bool VardikMi();
		void Ilerle();
		int& Getir();
		~Sayi();
	//private:
		Dugum* simdiki;

};
#endif