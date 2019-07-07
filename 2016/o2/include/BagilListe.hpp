/**      
 * @file		BagilListe.hpp
 * @description	BagilListe sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */

#ifndef BAGILLISTE_HPP
#define	BAGILLISTE_HPP
#include "Gezici.hpp"

class BagilListe
{
	public:
		BagilListe();
		BagilListe(int);
		bool DoluMu();
		int Uzunluk();
		Gezici DugumuBul(int);
		Gezici OncekiElemaniBul(int);
		void Ekle(int);
		void Ekle(int,int);
		void Sil();
		void Bosalt();
		//void Tersle(Dugum**);
		BagilListe& operator +(  BagilListe&);
		BagilListe* Tersle();
		//BagilListe operator+=(const BagilListe& bg);
		//BagilListe operator+(BagilListe& iki);
		Gezici Ilk();
		//friend ostream& operator<<(ostream& ekran,  BagilListe& sag);
		~BagilListe();
		int UzunlukDondur(int);
		int Uzunlukk();
		void ListeVeriDondur( );
		Dugum*& BaslamaDugumuDondur();
		//int dd;
	private:
		Dugum* baslamaDugumu;
		int uzunluk;
		int elde;

		

};
#endif