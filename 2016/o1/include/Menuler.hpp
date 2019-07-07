/**
 * @file		Menuler.hpp
 * @description	Menuler sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	1
 * @date		19.10.2016
 * @author		
 *
 *
 */
#ifndef MENULER_HPP
#define MENULER_HPP
#include "Kart.hpp"

class Menuler
{
	public:
		Menuler();
		Menuler(int);
		~Menuler();
		void MenuGiris();
		void MenuKartDegistir();
		void MenuTersCevir();

		void MenuSec(int);
		Kart*& HangiKart(int);
		void KartDegistir(Kart*&,Kart*&);
		void KartDizisiYaz();

		int*& KartNoDegistir(Kart*& ,Kart*& );
	private:
		int kartAdedi;		
		int ch;
		int kartDegistir1;
		int kartDegistir2;
		Kart* kartlar[52];
};
#endif