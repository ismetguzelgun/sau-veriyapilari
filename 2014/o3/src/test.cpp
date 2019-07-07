#include "Agac.hpp"

int main()
{

	agac* t1= new agac();

	ifstream file;
	file.open ("bilgi.txt");
	string ulke,sehir;
	char x ;

	while ( ! file.eof() )
	{
		ulke="";
		sehir="";
		x = file.get();

		while( x != '#') 
		{
			ulke = ulke + x;
			x = file.get();

			if(file.eof())break;
		}

				while(x!='\n' )
				{
					if(x=='#')
						x='\0';
					else
					{
						sehir = sehir + x;
						x = file.get();
				
				
						if(file.eof())break;
					}

				}
				t1->yerlestir_ulke(ulke,sehir);

	}
	
	t1->inorderTraversal();
	delete t1;
	return 0;
}