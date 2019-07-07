/**      
 * @file		Islem.hpp
 * @description	Islem sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		I-B
 * @assignment 	2	
 * @date		21.10.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				İlhan Kaya			b121210005@sakarya.edu.tr
 *
 */

#ifndef ISLEM_HPP
#define	ISLEM_HPP
#include "BagilListe.hpp"
class Islem
{
	public:
		Islem();
		~Islem();
		int KarakterdenSayiyaDondur(char);
		void ilkListeYarat(string);
		void ikinciListeYarat(string); 
		void Topla();

	private:

		BagilListe* liste1;
		BagilListe* liste2;
		BagilListe* liste3;


};

#endif