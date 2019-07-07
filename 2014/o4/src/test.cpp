/**      
 * @file		test.cpp
 * @description	test uygulaması
 * @course		I-B
 * @assignment 	4	
 * @date		06.12.2014
 * @author		İsmet 	GÜZELGÜN	b121210025@sakarya.edu.tr 
 *				İbrahim AKDAĞ		b121210027@sakarya.edu.tr
 *				Taşkın 	TEMİZ		g101210009@sakarya.edu.tr
 *
 */
#include "Ulke.hpp"
int main()
{
	Ulke* uk = new Ulke();
	string ulke="";
	string sehir="";
	char x;
	ifstream file;

	file.open("bilgi.txt");
	while (!file.eof())
	{
		ulke = "";
		sehir = "";
		x = file.get();
		while (x != '#')
		{
			ulke = ulke + x;
			x = file.get();

			if (file.eof())
				break;
		}

		while (x != '\n')
		{
			if (x == '#')
				x = '\0';
			else
			{
				sehir = sehir + x;
				x = file.get();

				if (file.eof())
					break;
			}
		
		}
		uk->yerlestir(new UlkeDugum(ulke), sehir);
	}
	cout<<"INORDER OKUMA";
	uk->inOrder();
	cout<<endl;
	
	delete uk;
	system("pause");
	return 0;
}