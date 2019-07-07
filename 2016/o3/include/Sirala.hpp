/**      
 * @file		Sirala.hpp
 * @description	Sirala sınıfına ait kütüphane dosyaları
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
#ifndef SIRALA_HPP
#define SIRALA_HPP
#include "IkiliAramaAgaci.hpp"
class Sirala
{
	public:
	Sirala(string);
	Sirala();
	~Sirala();

	private:
	IkiliAramaAgaci* ag;
	int KarakterdenSayiya(char);
	void Oku(string);
};
#endif