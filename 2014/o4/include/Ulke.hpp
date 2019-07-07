/**      
 * @file		Ulke.hpp
 * @description	Ulke sınıfına ait kütüphane
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */

#ifndef ULKE_HPP
#define ULKE_HPP
#include "IkiliAramaAgaci.hpp"
class Ulke:public IkiliAramaAgaci
{
public:
	Ulke();
	~Ulke();
	void inOrder();
	void yerlestir(UlkeDugum* , string );
private:
	UlkeDugum* root;
	UlkeDugum* dugumAra(string );
	bool dugumKontrol(string );
	void inOrderSirala(UlkeDugum* );
};
#endif