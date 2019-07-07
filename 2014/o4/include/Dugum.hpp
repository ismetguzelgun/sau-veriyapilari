/**      
 * @file		Dugum.hpp
 * @description	Dugum sınıfına ait Kütüphane
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Dugum
{
public:
	Dugum* sol;
	Dugum* sag;
	string veri;
	Dugum();
	Dugum(string);
	~Dugum();

};
#endif