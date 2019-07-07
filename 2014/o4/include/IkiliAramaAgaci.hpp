/**      
 * @file		IkiliAramaAgaci.hpp
 * @description	IkiliAramaAgaci sınıfına ait kütüphane
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */

#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP
#include "UlkeDugum.hpp"

class IkiliAramaAgaci
{
public:
	virtual void inOrder();
	virtual void yerlestir(UlkeDugum* );
	virtual UlkeDugum* dugumAra(string );
	virtual bool dugumKontrol(string );
	virtual void inOrderSirala(UlkeDugum* );
	UlkeDugum* root;
	IkiliAramaAgaci();
	~IkiliAramaAgaci();
};
#endif