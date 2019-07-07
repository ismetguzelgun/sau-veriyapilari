/**      
 * @file		Dugum.cpp
 * @description	Dugum sınıfına ait fonksiyon tanımlamaları ve içerikleri
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#include "Dugum.hpp"
Dugum::Dugum()
{
	sol=NULL;
	sag=NULL;
	veri="";
}
Dugum::Dugum(string st)
{
	sol= NULL;
	sag= NULL;
	veri=st;
}
Dugum::~Dugum()
{
}