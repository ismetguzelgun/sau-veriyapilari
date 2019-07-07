/**      
 * @file		KuyrukDugum.hpp
 * @description	KuyrukDugum sınıfına ait kütüphane dosyaları
 * @course		II-A
 * @assignment 	3	
 * @date		10.12.2016
 * @author		
 *								
 *
 */
#ifndef KUYRUKDUGUM_HPP
#define KUYRUKDUGUM_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
class KuyrukDugum
{
	public:
	KuyrukDugum();
	int dugumVeri;
	KuyrukDugum* bag;
	~KuyrukDugum();
};
#endif