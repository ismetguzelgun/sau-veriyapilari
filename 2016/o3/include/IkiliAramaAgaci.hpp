/**      
 * @file		IkiliAramaAgaci.hpp
 * @description	IkiliAramaAgaci sýnýfýna ait kütüphane dosyalarý
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
 #ifndef IKILIARAMAAGACI_HPP
 #define IKILIARAMAAGACI_HPP
 #include "AgacDugum.hpp"
 class IkiliAramaAgaci
 {
	 public:
	 
	 bool AgacBosMu() const;
	 void InOrderSirala() const;
	 void PreOrderSirala() const;
	 void PostOrderSirala() const;
	 int AgacBoyu() const;
	 int AgacDugumSayisi() const;
	 int AgacDalSayisi() const ;
	 void AgaciYokEt();
	 IkiliAramaAgaci(const IkiliAramaAgaci& digerAgac);
	 IkiliAramaAgaci();
	 ~IkiliAramaAgaci();
	 const IkiliAramaAgaci& operator=(const IkiliAramaAgaci& digerAgac);
	 bool Ara(const int&) const;
	 void Ekle(Kuyruk*&) ;
	 //void Sil(const int&) const;
	 private:
	 AgacDugum* root;
	 void AgacKopyala(AgacDugum* &kopyalanmisAgacKok, AgacDugum* digerAgacKok);
	 void YokEt(AgacDugum* &p);
	 void InOrder(AgacDugum* p) const;
	 void PreOrder(AgacDugum* p) const;
	 void PostOrder(AgacDugum* p) const;
	 int  Yukseklik(AgacDugum* p) const;
	 int  Max(int , int ) const;
	 int  DugumSayisi(AgacDugum* p) const;
	 int  DalSayisi(AgacDugum* p) const;
 };
 #endif