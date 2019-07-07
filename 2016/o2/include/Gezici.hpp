/**      
 * @file		Gezici.hpp
 * @description	Gezici sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */
 
#ifndef GEZICI_HPP
#define	GEZICI_HPP
#include "Dugum.hpp"
class Gezici
{
	public:
		Gezici();
		Gezici(Dugum*);
		bool VardikMi();
		void Ilerle();
		int& Getir();
		~Gezici();
	//private:
		Dugum* simdiki;

};
#endif