#include<stdio.h>
#include<windows.h>
int faktoriyel(int n)
{
	if(n<=1)
	{return 1;
	}
	else
   {return n*(faktoriyel(n-1));
   }
}
int main()
{   printf("Recursion fonksiyonlari dongüler yerine kullanildiði ve istenilen yerde cagrilabildigi icin avantajlidir.\n\n");
	int say,fak;
	printf("faktoriyeli alinacak sayiyi giriniz.\n");
	scanf("%d",&say);
	fak=faktoriyel(say);
	printf("%d nin faktoriyeli = %d \n\n",say,fak);
	return 1;
	
 

	
}

