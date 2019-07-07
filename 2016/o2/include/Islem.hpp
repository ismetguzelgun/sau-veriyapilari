/**      
 * @file		Islem.hpp
 * @description	Islem sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */

#ifndef ISLEM_HPP
#define	ISLEM_HPP
#include "Sayi.hpp"
class Islem
{
	public:
		Islem();
		~Islem();
		int KarakterdenSayiyaDondur(char);
		void ilkListeYarat(string);
		void ikinciListeYarat(string); 
		void Topla();
		void YokEt();
	private:

		//Sayi* sayi[3];
		Sayi* sayi2;
		Sayi* sayi3;
		Sayi* sayi1;

};

#endif