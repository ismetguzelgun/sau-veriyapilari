#include "Agac.hpp"
//Kurucu
agac::agac()
{
	root=NULL;

}
//Aynı degerin daha önce eklenip eklenmediğini kontrol eden method
bool agac::dugumKontrol(string s)
{
	dugum* cr;
	bool found = false;
	if(root==NULL)
		cout<<"olmadi";
	else
	{
		cr=root;
		while(cr!= NULL && found!=true)
		{
			if(s.compare(cr->ulke)==0)
				found= true;
			else if(s.compare(cr->ulke)<0)
				cr=cr->sol_link;
			else if(s.compare(cr->ulke)>0)
				cr=cr->sag_link;
			else
				break;
		
		}
	}
	return found;	
}
//Yukaridaki fonskiyonun doğru olması durumunda çağrılmak üzere
//düğüm döndüren fonksiyon
dugum* agac::dugumAra(string s)
{
	dugum* cr;
	if(root==NULL)
		cout<<"olmadi";
	else
	{
		cr=root;
		while(cr!= NULL)
		{
			if(s.compare(cr->ulke)==0)
				return cr;
			else if(s.compare(cr->ulke)<0)
				cr=cr->sol_link;
			else if(s.compare(cr->ulke)>0)
				cr=cr->sag_link;
			else
				break;
		
		}
	}

}
//Okunan degerleri agaca yerlestiren fonksiyon
void agac::yerlestir_ulke(string ulke,string sehir)
{
	if(root==NULL)
	{
		root = new dugum(ulke,sehir);
		return;
	}
	dugum* gecici=root;
	dugum* dd;

	/*while(true)
	{*/
		if(dugumKontrol(ulke))
		{
			
			dd=dugumAra(ulke);
			if(sehir.compare(dd->psehir->sehir)<0)
			{
				if(dd->psehir->sol_link!=NULL)
					dd->psehir=dd->psehir->sol_link;
				else
				{
					dd->psehir->sol_link=new dugum(sehir);
					//break;
					
				}
			}
			else if(sehir.compare(dd->psehir->sehir)>0)
			{
				if(dd->psehir->sag_link!=NULL)
					dd->psehir=dd->psehir->sag_link;
				else
				{
					
					dd->psehir->sag_link=new dugum(sehir);
					//break;
				
				}
			}
		}
	
		else
		{
		
			if(ulke.compare(gecici->ulke)<0)
			{
				if(gecici->sol_link!=NULL)
					gecici=gecici->sol_link;
				else
				{
					gecici->sol_link=new dugum(ulke,sehir);
					//break;
				}
			}
			else if(ulke.compare(gecici->ulke)>0)
			{
				if(gecici->sag_link !=NULL)
					gecici=gecici->sag_link;
				else
				{
					gecici->sag_link=new dugum(ulke,sehir);
					//break;
				}
			}

		}
	//}
}
//
void agac::inorderTraversal()
{
	inorderT(root,root->psehir);
}
//inorder dolanım yaparak yazdıran method
void agac::inorderT(dugum* t,dugum* s)
{
	if(t!=NULL && s!=NULL)
	{
		
		inorderT(t->sol_link,s->sol_link);
		cout<<t->ulke<<"\n"<<s->sehir<<"\n";
		inorderT(t->sag_link,s->sag_link);
		
	}
}
agac::~agac()
{



}