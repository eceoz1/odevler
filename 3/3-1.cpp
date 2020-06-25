#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct rehber
{
	char *isim; //kaydedilecek ki�inin ismi
	int num;		//kaydedilecek numara
};
void guncelle()
{
	typedef rehber xyz;
	int ynum; //yeni numara icin
	printf("Guncellemek istediginiz kisinin ismini giriniz\n");
	char aranan[30];
	scanf("%s", &aranan);
	FILE *fp = fopen("kayit.txt", "r+or");
	xyz okunan;
	okunan.isim = (char *)malloc(sizeof(char) * 100);
	printf("lutfen kisinin yeni numarasini giriniz");
	scanf("%d", &ynum);
	while (!feof(fp))
	{
		fscanf(fp, "%s %d", okunan.isim, ynum);
		fprintf(fp, "%s %d", okunan.isim, ynum);
	}
}
int main()
{
	typedef rehber xyz;
	int secim;
	while (1)
	{
		printf("TELEFON REHBERI\n");
		printf("_________________\n");
		printf("1. Kayit\n");
		printf("2. Guncelle\n");
		printf("3. Ara\n");
		printf("4. Sil\n");
		printf("5. Cik\n");
		printf("lutfen Yukardaki islemlerden yapmak istediginiz islemin numarasini giriniz");
		scanf("%d", &secim);
		if (secim == 1)
		{

			xyz okunan;
			okunan.isim = (char *)malloc(sizeof(char) * 100);
			printf("Kaydedilecek kisinin ismini giriniz");
			scanf("%s", okunan.isim);
			printf("Kaydedilecek kisinin numarasini giriniz");
			scanf("%d", &okunan.num);
			FILE *fp = fopen("kayit.txt", "a");
			fprintf(fp, "%s %d\n", okunan.isim, okunan.num);
			fclose(fp);
		}
		if (secim == 2)
		{

			guncelle();
		}
		if (secim == 3)
		{
			printf("Bulmak istediginiz kisinin ismini giriniz\n");
			char aranan[30];
			scanf("%s", &aranan);
			FILE *fp = fopen("kayit.txt", "r+or");
			xyz okunan;
			okunan.isim = (char *)malloc(sizeof(char) * 100);
			scanf("%d", &okunan.num);
			printf("%d", okunan.num);
		}
		if (secim == 4)
		{
			char istenenkisi[30]; //numarasini silmek istedigimiz kisi
			printf("Numarasini silmek istedigini kisinin ismini giriniz");
			scanf("%s", &istenenkisi);
			FILE *fp = fopen("kayit.txt", "r+or");
			xyz okunan;
			okunan.isim = (char *)malloc(sizeof(char) * 100);
			printf("%s Numarasi bulunamamaktadir\n", okunan.isim);
		}
		if (secim == 5)
		{
			break;
		}
	}
	return 0;
}
