#include <stdio.h>
#include <stdlib.h>

struct Kisi
{
	int telefon_numarasi;
	char isim[50];
	char soyisim[50];
};

void menu()
{
	printf("Telefon Rehberi\n");
	printf("----------------------\n");
	printf("1- Kayıt\n");
	printf("2- Güncelle\n");
	printf("3- Ara\n");
	printf("4- Sil\n");
	printf("5- Çık\n");
}

void kayit()
{
	char isim[50];
	char soyisim[50];
	char tel_no[10];

	printf("Lütfen isim giriniz (Max 50 karakter): ");
	while (getchar() != '\n')
		;
	scanf("%s", isim);

	printf("Lütfen soyisim giriniz (Max 50 karakter): ");
	while (getchar() != '\n')
		;
	scanf("%s", soyisim);

	printf("Lütfen telefon numarasını giriniz (10 karakter): ");
	while (getchar() != '\n')
		;
	scanf("%s", tel_no);

	FILE *fp = fopen("rehber.txt", "a");

	fprintf(fp, "%s\t|\t%s %s\n", &tel_no, &isim, &soyisim);
	fclose(fp);
}

void guncelle()
{
	int c;
	int yeni_numara;
	char kisi[101];

	printf("lütfen isim ve soyisim giriniz (Max 101 karakter): ");
	while (getchar() != '\n')
		;
	scanf("%s", &kisi);

	FILE *fp = fopen("kayit.txt", "r+or");
}

int main()
{
	int secim;

	printf("20180805021 | Ece ÖZ\n");

	menu();

	scanf("%d", &secim);

	if (secim > 5 || secim < 0)
	{
		menu();
	}
	else
	{
		switch (secim)
		{
		case 1:
			kayit();
			break;
		case 2:
			guncelle();
			break;
		case 3:
			/* code */
			break;
		case 4:
			/* code */
			break;
		case 5:
			/* code */
			break;
		}
	}

	return 0;
}