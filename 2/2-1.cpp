#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci
{
	char *isim;
	char *bolum;
	int no;
};

int main()
{
	int n;
	typedef ogrenci xyz;
	printf("N eleman sayisini giriniz");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		xyz okunan;
		okunan.isim = (char *)malloc(sizeof(char) * 100);

		printf("ismini giriniz\n");
		scanf("%s", okunan.isim);

		okunan.bolum = (char *)malloc(sizeof(char) * 100);

		printf("bolumunu giriniz\n");
		scanf("%s", okunan.bolum);

		printf("numarasini giriniz\n");
		scanf("%d", &okunan.no);

		FILE *fp = fopen("kayit.txt", "a");

		fprintf(fp, "%s   %s   %d \n", okunan.isim, okunan.bolum, okunan.no);
		fclose(fp);
	}
	//Bu soruda dinamik bellek kullan�m� gereksiz ancak ben kendimi geli�tirmek i�in b�yle yapt�m
}
