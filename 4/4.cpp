#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h> //saati almak i�in tanimladim.
#include <windows.h>

main()
{

	HANDLE hComm = CreateFile("COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0); // COM3 portunu okuma ve yazma i�lemleri i�in a�

	if (hComm == INVALID_HANDLE_VALUE)
	{ // porta eri�im sa�lanamad�ysa

		if (GetLastError() == ERROR_FILE_NOT_FOUND)
		{ // olu�an hata "bulunamad�" ise

			printf("port erisimi yok\n"); // ekrana "port erisimi yok" yaz
		}
	}

	DCB dcbSerialParams = {0};

	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

	if (!GetCommState(hComm, &dcbSerialParams))
	{ // seri ileti�im ayarlar� uygulanamad�ysa

		printf("baglanti hatasi\n"); // ekrana "baglanti hatasi" yaz

		return EXIT_FAILURE; // program� sonland�r
	}

	// seri ileti�im ayarlar�
	dcbSerialParams.BaudRate = CBR_9600;	 // 9600 h�z�nda
	dcbSerialParams.ByteSize = 8;					 // 8 bitlik paketler halinde
	dcbSerialParams.Parity = NOPARITY;		 // e�lik biti yok
	dcbSerialParams.StopBits = ONESTOPBIT; // 1 tane stop biti var

	if (!SetCommState(hComm, &dcbSerialParams))
	{ // seri ileti�im ayarlar� uygulanamad�ysa

		printf("baglanti hatasi\n"); // ekrana "baglanti hatasi" yaz

		return EXIT_FAILURE; // program� sonland�r
	}

	DWORD dwWrite;
	char secim = 0; // kullan�c�n�n girdi�i de�eri alan de�i�ken

	while (1)
	{ // sonsuz d�ng�
		time_t t;
		struct tm *zaman_bilgisi;

		time(&t);
		zaman_bilgisi = localtime(&t);

		printf("secim giriniz\n1-Istenen Ledi yakma\n2-Istenen Ledi sondurme\n3-Istenen Ledi istenen surede yakma\n4-Senaryo\n5-Cikis\n");
		fflush(stdin);
		scanf("%c", &secim);

		FILE *dosya = fopen("Islem_saatleri.txt", "a+");
		fprintf(dosya, "%s  Istenilen islem girildi.\n", asctime(zaman_bilgisi));

		switch (secim)
		{

		case '1':
			fflush(stdin);
			WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			char yanan;																//yanacak olan� al�yor
			printf("hangi ledi yakal�m\n");
			scanf("%c", &yanan); //yanacak olan� al�yor

			WriteFile(hComm, &yanan, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			fprintf(dosya, "%s  Istenilen led yakilldi.\n", asctime(zaman_bilgisi));
			break;

		case '2':
			fflush(stdin);
			WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			char sonen;
			printf("hangi ledi sonsun\n");
			scanf("%c", &sonen);

			WriteFile(hComm, &sonen, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			fprintf(dosya, "%s  Istenilen led sonduruldu.\n", asctime(zaman_bilgisi));
			break;

		case '3':
			fflush(stdin);
			WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			char syanan;															//s�reyle yanan gibisinden farkl� de�i�ken tan�mlad�m belli s�re beklicez ya o y�zden ba�a s att�m
			printf("Hangi ledi yakalim\n");
			char sure;
			scanf("%c", &sure);
			WriteFile(hComm, &sure, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			fflush(stdin);
			printf("Kac saniye acik kalsin\n");
			scanf("%c", &syanan);											 //s�reyle yanan gibisinden farkl� de�i�ken tan�mlad�m belli s�re beklicez ya o y�zden ba�a s att�m
			WriteFile(hComm, &syanan, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			fflush(stdin);
			//Not hocam burda sure ile synan da printfleri degistirdim mecburen ��nk� i�in i�inden ��kamad�m s�re diye ald���m de�i�keni arduino da led olarak al�yor o y�zden pratik ��z�m olrak printf lerin i�in de�i�tirdim.
			fprintf(dosya, "%s  Istenilen led istenilen surede yakildi.\n", asctime(zaman_bilgisi));
			break;

		case '4':
			fflush(stdin);
			WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
			char islem;																//A�a��daki men�de yap�l�cak islemin de�erini al�r
			printf("\n1-Karasimsek\n2-Sirali Yakma\n3-Polis Cakari\n");
			scanf("%c", &islem);

			fprintf(dosya, "%s  Senaryo secimi yapildi.\n", asctime(zaman_bilgisi));
			switch (islem)
			{
			case '1':

				WriteFile(hComm, &islem, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
				fprintf(dosya, "%s  Senaryo secimlerinden karasimsek yapildi.\n", asctime(zaman_bilgisi));
				break;

			case '2':

				WriteFile(hComm, &islem, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
				fprintf(dosya, "%s  Senaryo secimlerinden seri yakma yapildi.\n", asctime(zaman_bilgisi));
				break;

			case '3':

				WriteFile(hComm, &islem, 1, &dwWrite, 0); // seri porta yaz, yaz�lan de�eri "secim" de�i�kenine ata
				fprintf(dosya, "%s  Senaryo secimlerinden polis cakari yapildi.\n", asctime(zaman_bilgisi));
				break;
			}
			break;
		}
		if (secim == '5')
		{
			printf("Cikis yapiliyor.\n");
			fprintf(dosya, "%s  cikis yapildi.\n", asctime(zaman_bilgisi));
			break;
		}

		fclose(dosya);
		Sleep(10);

		//secim ==5 ilk yapt���m switch'in d���na yazd�m ki ��k�� yap�ld���nda d�ng�den ��ks�n.
		system("cls");
	}

	CloseHandle(hComm); // port i�lemlerini kapat
}
