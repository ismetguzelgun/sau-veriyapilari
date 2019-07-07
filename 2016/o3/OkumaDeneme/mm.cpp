#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int dd(char x)
{
	int sayi=(int) x-48;
	return sayi;
}
int main()
{
	ifstream file;
	file.open ("sayilar.txt");
	int sayi[15];
	int sayi2[7];
	char x ;
	int d=0;
	int i=0;
	while ( ! file.eof() )
	{
		x = file.get();
		while(x!='\n' )
		{

			
			x = file.get();
			sayi[i] = dd(x);
		
			i++;	
			
			if(file.eof())break;

		}
		//cout<<endl;
		d++;
		//t1->yerlestir_ulke(ulke,sehir);
		
	}
	for(int j=0;j<10;j++)
		cout<<sayi[j]<< ' ' ;
	cout<<endl;

	//t1->inorderTraversal();
	//delete t1;
	return 0;
}