#include <stdio.h>
#include <stdlib.h>

/*
https://stackoverflow.com/questions/39537753/why-inside-a-loop-scanf-with-d-does-not-wait-for-the-user-input-in-case-it-r
*/

struct Ogrenci
{
	int ogrenci_no;
	char ad[50];
	char soyad[50];
};

int main()
{
	int n;

	printf("20180805021 | Ece ÖZ\n");
	printf("Öğrenci sayısını giriniz: ");

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		printf("---------------------------------------------------\n");

		struct Ogrenci o;

		printf("Öğrenci numarasını giriniz: ");
		while (getchar() != '\n')
			;
		scanf("%d", &o.ogrenci_no);

		printf("Öğrenci adını giriniz (Max 50 karakter): ");
		while (getchar() != '\n')
			;
		scanf("%s", o.ad);

		printf("Öğrenci soyadını giriniz (Max 50 karakter): ");
		while (getchar() != '\n')
			;
		scanf("%s", o.soyad);

		FILE *fp = fopen("ogrenciler.txt", "a");

		fprintf(fp, "%d\t|\t%s %s\n", o.ogrenci_no, &o.ad, &o.soyad);
		fclose(fp);
	}

	printf("---------------------------------------------------\n");
	printf("KAYDEDİLDİ!\n");

	return 0;
}
