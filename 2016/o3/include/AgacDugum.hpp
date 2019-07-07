/**      
 * @file		AgacDugum.hpp
 * @description	AgacDugum s�n�f�na ait k�t�phane dosyalar�
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
 #ifndef AGACDUGUM_HPP
 #define AGACDUGUM_HPP
 #include "Kuyruk.hpp"
 class AgacDugum
 {
	 public:
	 AgacDugum();
	 ~AgacDugum();
	 AgacDugum(Kuyruk*&);
	 int agacVeri;
	 Kuyruk* agacKuyruk;
	 AgacDugum* sol;
	 AgacDugum* sag;
 };
 #endif