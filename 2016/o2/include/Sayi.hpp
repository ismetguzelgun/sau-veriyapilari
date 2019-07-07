/**      
 * @file		Sayi.hpp
 * @description	Sayi sınıfı için gerekli üye fonksiyonları içeren başlık dosyası
 * @course		II-A
 * @assignment 	2	
 * @date		10.11.2016
 * @author		
 *								
 *
 */
 #ifndef SAYI_HPP
 #define SAYI_HPP
 #include "BagilListe.hpp"
 class Sayi
 {
	public:
	Sayi();
	~Sayi();
	BagilListe*& SayiListesiDondur();
	friend ostream& operator<<(ostream& ekran,  Sayi& sag);
	Sayi& operator +(  Sayi&);
	void ToplamiYaz();
	private:
		BagilListe* sayiListesi;
 };
 #endif