/**      
 * @file		Dugum.hpp
 * @description	Dugum sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	1	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */

#ifndef DUGUM_HPP
#define	DUGUM_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Dugum
{
	public:
		Dugum(int,Dugum*);
		Dugum();
		int& Getir();
		int dugumveri;
		Dugum* ileri;
		int d;
};
#endif
