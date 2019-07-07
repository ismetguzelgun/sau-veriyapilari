/**      
 * @file		SepetKontrol.hpp
 * @description	SepetKontrol sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	1	
 * @date		20.09.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *
 */

#ifndef		SEPETKONTROL_HPP
#define		SEPETKONTROL_HPP
#include "Civi.hpp"

class SepetKontrol
{
	public:
		SepetKontrol();
		~SepetKontrol();
		void 	Yazdir();
		int 	DogruIndexiDondur(char);
		void 	Degistir(int,int);
		
	private:
		Dugum*	civiler[3];
		Civi* 	pcivi;
};
#endif