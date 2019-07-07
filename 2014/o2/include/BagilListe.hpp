/**      
 * @file		BagilListe.hpp
 * @description	BagilListe sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */

#ifndef BAGILLISTE_HPP
#define	BAGILLISTE_HPP
#include "Sayi.hpp"

class BagilListe
{
	public:
		BagilListe();
		BagilListe(int);
		bool DoluMu();
		int Uzunluk();
		Sayi DugumuBul(int);
		Sayi OncekiElemaniBul(int);
		void Ekle(int);
		void Ekle(int,int);
		void Sil();
		void Bosalt();
		//void Tersle(Dugum**);
		BagilListe& operator +(  BagilListe&);
		BagilListe* Tersle(BagilListe*);
		//BagilListe operator+=(const BagilListe& bg);
		//BagilListe operator+(BagilListe& iki);
		Sayi Ilk();
		friend ostream& operator<<(ostream& ekran,  BagilListe& sag);
		~BagilListe();
		int UzunlukDonder(int);
		int Uz();
		//int dd;
	private:
		Dugum* baslamaDugumu;
		int uzunluk;
		int elde;

		

};
#endif