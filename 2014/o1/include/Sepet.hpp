/**      
 * @file		Sepet.hpp
 * @description	Sepet sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	1	
 * @date		19.09.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *
 */

#ifndef		SEPET_HPP
#define		SEPET_HPP
#include <iostream>
#include <cstdlib>
using namespace std;

class Sepet
{
	public:
		Sepet(int);
		char	SepetAdiBelirle(int);
		char 	SepetAdiDondur();
		void 	SepetCiz();

	private:
		int		sepNo;
		char 	sepAd;	
};
#endif