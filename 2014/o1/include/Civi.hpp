/**      
 * @file		Civi.hpp
 * @description	Civi sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	1	
 * @date		19.09.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *
 */

#ifndef		CIVI_HPP
#define		CIVI_HPP
#include 	"Sepet.hpp"

class Civi
{
	public:		
		Civi(int);
		~Civi();
		void CiviYazdir();
		char CiviyeSepetAdiDondur();
		
	private:
		Sepet*	sepet [];
		int 	civiNo;	
};
#endif