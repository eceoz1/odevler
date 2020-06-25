#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>//saati almak için tanimladim.
#include<windows.h>
main() {

HANDLE hComm = CreateFile("COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0); // COM3 portunu okuma ve yazma iþlemleri için aç
 
if (hComm == INVALID_HANDLE_VALUE) { // porta eriþim saðlanamadýysa

if (GetLastError() == ERROR_FILE_NOT_FOUND) { // oluþan hata "bulunamadý" ise

printf("port erisimi yok\n") ; // ekrana "port erisimi yok" yaz

}

}

DCB dcbSerialParams = {0};

dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

if (!GetCommState(hComm, &dcbSerialParams)) { // seri iletiþim ayarlarý uygulanamadýysa

printf("baglanti hatasi\n"); // ekrana "baglanti hatasi" yaz

return EXIT_FAILURE; // programý sonlandýr

}

// seri iletiþim ayarlarý
dcbSerialParams.BaudRate = CBR_9600; // 9600 hýzýnda
dcbSerialParams.ByteSize = 8; // 8 bitlik paketler halinde
dcbSerialParams.Parity = NOPARITY; // eþlik biti yok
dcbSerialParams.StopBits = ONESTOPBIT; // 1 tane stop biti var

if (!SetCommState(hComm, &dcbSerialParams)) { // seri iletiþim ayarlarý uygulanamadýysa

printf("baglanti hatasi\n"); // ekrana "baglanti hatasi" yaz

return EXIT_FAILURE; // programý sonlandýr

}


DWORD dwWrite;
char  secim=0; // kullanýcýnýn girdiði deðeri alan deðiþken

 
while (1)
{ // sonsuz döngü
 time_t t;
  struct tm *zaman_bilgisi;

  time (&t);
  zaman_bilgisi = localtime (&t);

  



printf("secim giriniz\n1-Istenen Ledi yakma\n2-Istenen Ledi sondurme\n3-Istenen Ledi istenen surede yakma\n4-Senaryo\n5-Cikis\n");
fflush(stdin);
scanf("%c",&secim);

FILE *dosya=fopen("Islem_saatleri.txt","a+");
fprintf(dosya,"%s  Istenilen islem girildi.\n",asctime(zaman_bilgisi));

switch(secim)
{
	
case '1':
fflush(stdin);
WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
char yanan;//yanacak olaný alýyor
printf("hangi ledi yakalým\n");
scanf("%c",&yanan);//yanacak olaný alýyor

WriteFile(hComm, &yanan, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
fprintf(dosya,"%s  Istenilen led yakilldi.\n",asctime(zaman_bilgisi));
break ;

case '2':
fflush(stdin);	
WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
char sonen;	
printf("hangi ledi sonsun\n");
scanf("%c",&sonen);

WriteFile(hComm, &sonen, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
fprintf(dosya,"%s  Istenilen led sonduruldu.\n",asctime(zaman_bilgisi));
break ;

case '3':
fflush(stdin);	
WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
char syanan;//süreyle yanan gibisinden farklý deðiþken tanýmladým belli süre beklicez ya o yüzden baþa s attým
printf("Hangi ledi yakalim\n");
char sure;
scanf("%c",&sure);
WriteFile(hComm, &sure, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
fflush(stdin);
printf("Kac saniye acik kalsin\n");
scanf("%c",&syanan);//süreyle yanan gibisinden farklý deðiþken tanýmladým belli süre beklicez ya o yüzden baþa s attým
WriteFile(hComm, &syanan, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
fflush(stdin);	
//Not hocam burda sure ile synan da printfleri degistirdim mecburen çünkü iþin içinden çýkamadým süre diye aldýðým deðiþkeni arduino da led olarak alýyor o yüzden pratik çözüm olrak printf lerin için deðiþtirdim.
fprintf(dosya,"%s  Istenilen led istenilen surede yakildi.\n",asctime(zaman_bilgisi));
break ;

case '4':
fflush(stdin);
WriteFile(hComm, &secim, 1, &dwWrite, 0); //seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata	
char islem;//Aþaðýdaki menüde yapýlýcak islemin deðerini alýr
printf("\n1-Karasimsek\n2-Sirali Yakma\n3-Polis Cakari\n");
scanf("%c",&islem);

fprintf(dosya,"%s  Senaryo secimi yapildi.\n",asctime(zaman_bilgisi));
switch(islem){
case '1':
	
	WriteFile(hComm, &islem, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
	fprintf(dosya,"%s  Senaryo secimlerinden karasimsek yapildi.\n",asctime(zaman_bilgisi));
	break;


case '2':
	
	WriteFile(hComm, &islem, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
	fprintf(dosya,"%s  Senaryo secimlerinden seri yakma yapildi.\n",asctime(zaman_bilgisi));
	break;

case '3':
	
	WriteFile(hComm, &islem, 1, &dwWrite, 0); // seri porta yaz, yazýlan deðeri "secim" deðiþkenine ata
	fprintf(dosya,"%s  Senaryo secimlerinden polis cakari yapildi.\n",asctime(zaman_bilgisi));
	break;

}
break;


}
if (secim=='5'){
	printf("Cikis yapiliyor.\n");
	fprintf(dosya,"%s  cikis yapildi.\n",asctime(zaman_bilgisi));
	break;
}

fclose(dosya);
Sleep(10);

//secim ==5 ilk yaptýðým switch'in dýþýna yazdým ki çýkýþ yapýldýðýnda döngüden çýksýn.
system("cls");
}

CloseHandle(hComm); // port iþlemlerini kapat

}
