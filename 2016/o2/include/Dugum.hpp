/**      
 * @file		Dugum.hpp
 * @description	Dugum sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
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
		
};
#endif
