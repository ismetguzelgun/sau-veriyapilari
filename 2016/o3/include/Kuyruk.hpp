/**      
 * @file		Kuyruk.hpp
 * @description	Kuyruk sýnýfýna ait kütüphane dosyalarý
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
 #ifndef KUYRUK_HPP
 #define KUYRUK_HPP
 #include "KuyrukDugum.hpp"
 class Kuyruk
 {
	 
 public:
	Kuyruk();
	~Kuyruk();
	//Kuyruk(const Kuyruk&);
	bool BosMu() const;
	bool DoluMu() const;
	int KuyrukOn() const;
	int KuyrukArka() const;
	void KuyrukBaslat();
	void Ekle(const int& );
	void Sil();
	int KuyrukToplam() const;
	int KuyrukDegerleriniTopla()  ;

 private:
	KuyrukDugum* kuyrukOnu;
	KuyrukDugum* kuyrukArkasi;
	KuyrukDugum* yeniDugum;
	int kuyrukToplam;
	
 };
 #endif