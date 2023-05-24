

// PROGRAMIN GÝRÝÞ ÞÝFRESÝ 2020'DÝR.


#include<stdio.h>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>


// FONKSÝYONLAR

void sifre(); 
void ana_menu(); 
void kitap_ekleme();
void kitap_silme();
void kitap_duzenleme(); 
void kitap_arama(); 
void kitap_listeleme();
void kitap_odunc_alma();


// GLOBAL DEÐÝÞKENLER
int i=0, uyum=0, bulundu=0;      // Programýn her yerinde deðiþkenleri kullanabilmemiz için
char karar=0;					 // deðiþkenleri global olarak tanýmladýk. 

// KÝTAP BÝLGÝLERÝNÝ TUTMAK ÝÇÝN STRUCT
struct kitaplar              // Kitaplar adýnda bir yapý oluþturarak 
{							 // birden fazla deðiþkeni bir arada
	int kitap_id;            // tutmayý saðladýk
	char kitap_adi[20];
	char yazar_adi[20];
	char aKisi_adi[20];
	char kitapTur[15];
	int gun;	
	
}kitapEklemeBilgileri;

void yerxy(short x, short y)  // Bu fonksiyon sayesinde komut penceresindeki yazýlarýn 
{							  // yerlerini deðiþtirebilmeyi saðladýk.
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int main() 
{	
	system("color a");
	sifre();
}





// ÞÝFRE 
void sifre()
{
	yerxy(30,1);
	printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
	yerxy(45,3);
	printf("KUTUPHANE SISTEMINE HOS GELDINIZ!");
	yerxy(30,5);
	printf("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-__-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");
	int sifre= 2020;
	int gsifre;
	
	yerxy(45,10);
	printf("Lutfen Sifrenizi Giriniz: ");
	scanf("%d", &gsifre);  // ÞÝFREYÝ ALDIK.
	yerxy(45,12);
	

	if (gsifre == 2020 ) {
	yerxy(30,14);
	printf("------------------------------------------------------------------");
	yerxy(50,16);
	printf("Girdiginiz Sifre Dogru!\n");
	yerxy(40,18);
	printf("Devam Etmek Icin Herhangi Bir Tusa Basiniz!\n");
	yerxy(30,20);
	printf("------------------------------------------------------------------");
	yerxy(60,22);
	getch();	
	ana_menu();	
	}
	
	
	else {
	int tekrarDeneGirdi;
	yerxy(45,14);
	printf("----------------------------------");
	yerxy(45,16);		
	printf("Girdiginiz sifre yanlis.\n");
	yerxy(45,18);
	printf("Tekrar denemek icin 1'e basiniz.\n");
	yerxy(45,20);
	printf("Cikis yapmak icin 0'a basiniz.\n");
	yerxy(45,22);
	
	switch (getch()) {     // getch() fonksiyonu sayesinde kullanýcýnýn herhangi 
					       // bir karaktere basarak döngüye girmesini saðladýk.
		case '1': {
			system("cls");
			main();
			break;
		}		
		
		case '0': {
			system("cls");
			yerxy(45,10);
			printf("Program sonlandi.");
			break;
		}			
		
	}
	
}
	
}




// ANA MENÜ
void ana_menu(void){
	
	int karar = 1;
	do{	
	system("cls");
	yerxy (40,3);
	printf("ANA MENU");
	yerxy (40,4);
	printf("__________________________________________________");
	yerxy (40,7);
	printf("1. Kitap Listesini Listeleme");
	yerxy (40,8);
	printf("-------------------------------------------------");
	yerxy (40,9);
	printf("2. Kitap Arama");
	yerxy (40,10);
	printf("-------------------------------------------------");
	yerxy (40,11);
	printf("3. Kitap Ekle");
	yerxy (40,12);
	printf("-------------------------------------------------");
	yerxy (40,13);
	printf("4. Kitap Bilgilerini Duzenleme");
	yerxy (40,14);
	printf("-------------------------------------------------");
	yerxy (40,15);
	printf("5. Kitap Silme");
	yerxy (40,16);
	printf("-------------------------------------------------");
	yerxy (40,17);
	printf("6. Kitap Odunc Alma");
	yerxy (40,18);
	printf("-------------------------------------------------");
	yerxy (40,19);
	printf("7. Cikis Yapmak Icin 7'ye Basiniz");
	yerxy (40,20);
	printf("--------------------------------------------------");
	yerxy (40,25);
	printf("Atakan Bayrak  Mustafa Berberler  Mehmet Umit Acik");
	yerxy (40,26);
	printf("__________________________________________________");
	
	
	
	switch (getch()) {	
		
		case '1': {
			kitap_listeleme();			
			break;
		}
		case '2': {
			kitap_arama();
			break;
		}
		case '3': {
			kitap_ekleme();
			break;
		}
		case '4': {
			kitap_duzenleme();
			break;
		}
		case '5': {
			kitap_silme();
			break;
		}
		case '6': {
			kitap_odunc_alma();
			break;
		}		
		case '7': {
			karar = 0;
			break;
		}
		default: {
			ana_menu();
			break;
		}
	
	}
							
	}while (karar != 0);		
}






// KÝTAP LÝSTELEME
void kitap_listeleme()
{	
	int j=11;
	FILE*fpointer;  // Dosya iþlemlerini yapabilmek için gerekli olan pointer'ý tanýmladýk.
	system("cls");
	fpointer=fopen("kitapKayit.txt","r");  // Dosyayý açabilmek için fopen() fonksiyonunu kullandýk.
	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP LISTESINI GORUNTULUYORSUNUZ      ******");
	yerxy(30,5);
	printf("*********************************************************");
	
	if(fpointer==NULL)  // Bu koþulu kullanarak dosyanýn açýlýp açýlamadýðýný kontrol ettik.
	{
		yerxy(30,10);	
		printf("Dosya Acma Islemi Basarisiz.");
		getch();
	}
	else
	{
		// 	fscanf() fonksiyonu sayesinde, fpointer adlý göstericinin gösterdiði dosyadan istenilen bilgileri okumayý saðladýk.		
		// != EOF sayesinde de, dosya sonuna gelene kadar döngünün devam etmesini saðladýk.
		while(fscanf(fpointer,"%i %s %s %s %s %i\n\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
		{
			yerxy(30,j);
			printf("---------------------------------------------------------");
			j = j+2;	
			yerxy(40,j);
			printf("Kitap ID: ");
			printf("%i",kitapEklemeBilgileri.kitap_id);
			j = j+2;
			yerxy(40,j);
			printf("Kitap Adi: ");
			printf("%s",kitapEklemeBilgileri.kitap_adi);
			j = j+2;
			yerxy(40,j);
			printf("Yazar Adi: ");
			printf("%s",kitapEklemeBilgileri.yazar_adi);
			j = j+2;
			yerxy(40,j);
			printf("Alan Kisinin Adi: ");
			printf("%s",kitapEklemeBilgileri.aKisi_adi);
			j = j+2;
			yerxy(40,j);
			printf("Kitap Turu: ");
			printf("%s",kitapEklemeBilgileri.kitapTur);
			j = j+2;
			yerxy(40,j);
			printf("Alinan Gun: ");
			printf("%i",kitapEklemeBilgileri.gun);
			j = j+2;
			yerxy(30,j);
			printf("---------------------------------------------------------");					
			j = j+2;			
		}		
	}
	j = j + 3;
	yerxy(30,j);	
	printf("Ana Menuye Donmek Icin Herhangi Bir Tusa Basiniz...");
	
	fclose(fpointer);   // fclose() fonksiyonu sayesinde dosyayý kapattýk.
	getch();
	ana_menu();


}




// KÝTAP ARAMA
void kitap_arama()
{
	int cikis;
	int bulundu=0;
	char ad[40];
	FILE *fpointer;   // Dosyayý açmak için yeniden pointer tanýmladýk.
	system("cls");  
	fpointer=fopen("kitapKayit.txt","rb");    // Dosyayý açtýk.
	yerxy(30,1); 
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP ARAMA EKRANINA HOS GELDINIZ      ******");
	yerxy(30,5);
	printf("*********************************************************");
	yerxy(37,7);
	printf("Bulmak Istediginiz Kitabin Adini Giriniz: ");
	fflush(stdin);	 // Boþluklu bir girdi dizisi alýrken, tampon bölge sonraki girdi için temizlenmez 
					 // ve ayný girdi için önceki girdiyi dikkate alýr. Bu sorunu çözmek için, tampon bölgedeki
					 // verileri silmek amacýyla fflush(stdin) kullandýk.
	scanf("%s",ad);
	ad[0]=toupper(ad[0]);   // toupper() fonksiyonu sayesinde, ad adlý dizideki 0. index'i büyük harfe çevirdik.
		
	
	while(fscanf(fpointer,"%i %s %s %s %s %i\n\n",&kitapEklemeBilgileri.kitap_id, kitapEklemeBilgileri.kitap_adi, kitapEklemeBilgileri.yazar_adi, kitapEklemeBilgileri.aKisi_adi, kitapEklemeBilgileri.kitapTur, &kitapEklemeBilgileri.gun)!=EOF)
	{
		if(strcmp(ad,kitapEklemeBilgileri.kitap_adi)==0)  // strcmp() fonksiyonu sayesinde, girilen ilk parametrenin 
		{												  // karakterleriyle ikinci parametrenin karakterlerini karþýlaþtýrdýk.
			yerxy(40,9);								  // Eðer bütün karakterler birbirine eþitse, strcmp() fonksiyonunun 
			printf("----------------------------------"); // yapýsý gereði 0 döndüðü için 0'a eþitledik. Böylece koþul doðruysa 
			bulundu=1;									  // altýndaki kodlar çalýþmýþ oldu.
			yerxy(30,11);	
			printf("Kitap ID: ");
			printf("%i",kitapEklemeBilgileri.kitap_id);
			yerxy(30,13);
			printf("Kitap Adi: ");
			printf("%s",kitapEklemeBilgileri.kitap_adi);
			yerxy(30,15);
			printf("Yazar Adi: ");
			printf("%s",kitapEklemeBilgileri.yazar_adi);
			yerxy(30,17);
			printf("Alan Kisinin Adi: ");
			printf("%s",kitapEklemeBilgileri.aKisi_adi);
			yerxy(30,19);
			printf("Kitap Turu: ");
			printf("%s",kitapEklemeBilgileri.kitapTur);
			yerxy(30,21);
			printf("Alinan Gun: ");
			printf("%i",kitapEklemeBilgileri.gun);
			break;
		}
	}
		yerxy(30,23);
		if(!bulundu) printf("Boyle Bir Kitap Bulunmamaktadir");
		fclose(fpointer);  // fclose() fonksiyonu ile dosyayý kapattýk.
		
		yerxy(30,25);	
		printf("Tekrar Arama Yapmak Icin 1, Cikis Icin 0\n");
		yerxy(30,26);	
		
		do{
		switch (getch()){
		case '1':{
			kitap_arama();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);
	
}





// KÝTAP EKLEME
void kitap_ekleme()
{
	
	system("cls");
	FILE *fpointer;   // Dosya iþlemlerini yapabilmek için yeniden pointer tanýmladýk.
	fpointer = fopen("kitapKayit.txt","a");
	int karar,cikis,karar2;
	int gun;
		
	// --------------- //
	
	do{		
	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP EKLEME EKRANINA HOS GELDINIZ     ******");
	yerxy(30,5);
	printf("*********************************************************");
	yerxy(30,7);
	printf("Eklemeye Gecmek Icin 1 / Ana Menu Icin 0");
	yerxy(30,9);	
	fflush(stdin);
	
	switch (getch()){
		case '1':{
			karar =2;
			break;
		}
		case '0':{
			ana_menu();
			break;
		}
		default: karar = 3;
	}
	}while(karar != 2);
	
	// ------------------- // Döngü
	system("cls");
	yerxy(30,11);
	printf("ADIM 1");	
	yerxy(30,13);
	printf("ONEMLI VERILERI GIRINIZ");
	yerxy(30,15);
	printf("------------------------------");	
	yerxy(30,17);
	printf("Kitap ID Numarasi: ");
	fflush(stdin);
	scanf("%i",&kitapEklemeBilgileri.kitap_id);
	system("cls");
	
	do
	{	
		yerxy(30,11);
		printf("ADIM 2");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Kitap Adi: ");
		fflush(stdin);		
		gets(kitapEklemeBilgileri.kitap_adi);  // gets() fonksiyonuyla birlikte kullanýcýdan veri aldýk.
		system("cls");
		kitapEklemeBilgileri.kitap_adi[0]=toupper(kitapEklemeBilgileri.kitap_adi[0]); // kitapEklemeBilgileri.kitap_adi'nin 0. indexini büyük harfe çevirdik
		for (i=0;i<strlen(kitapEklemeBilgileri.kitap_adi); ++i)  // strlen() fonksiyonu sayesinde, girilen kitap adýndaki karakter sayýsý kadar kere 
		{														 // döngünün dönmesini saðladýk.
			if(isalpha(kitapEklemeBilgileri.kitap_adi[i]))   // isalpha() fonksiyonu sayesinde ve [i] indexi sayesinde, girilen kitap adýndaki her
			{												 // karakterin alfabeden bir harf olup olmadýðýný kontrol ettik.
				uyum = 1;
			}
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{	
			yerxy(30,8);
			printf("!Kitabin Adi Sayi Iceremez!");
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 3");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Yazarin Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.yazar_adi);
		system("cls");
		kitapEklemeBilgileri.yazar_adi[0]=toupper(kitapEklemeBilgileri.yazar_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.yazar_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.yazar_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("!Yazarin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 4");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ:");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Alan Kisinin Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.aKisi_adi);
		system("cls");
		kitapEklemeBilgileri.aKisi_adi[0]=toupper(kitapEklemeBilgileri.aKisi_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.aKisi_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.aKisi_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("Alan Kisinin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
		do
			{
				yerxy(30,11);
				printf("ADIM 5");
				yerxy(30,13);
				printf("ONEMLI VERILERI GIRINIZ:");
				yerxy(30,15);
				printf("------------------------------");
				yerxy(30,17);
				printf("Kitabin Turu: ");
				fflush(stdin);
				gets(kitapEklemeBilgileri.kitapTur);
				system("cls");
				kitapEklemeBilgileri.kitapTur[0]=toupper(kitapEklemeBilgileri.kitapTur[0]);
				for (i=0;i<strlen(kitapEklemeBilgileri.kitapTur); ++i)
				{
					if(isalpha(kitapEklemeBilgileri.kitapTur[i]))
					uyum = 1;
					else
					{
						uyum = 0;
						break;
					}
				}
				if (!uyum)
				{
					yerxy(30,8);
					printf("!Kitabin Turu Sayi Iceremez!");
					
				}
			}while(!uyum);
			kitapEklemeBilgileri.gun = 0;
			
	// fprintf() fonksiyonu sayesinde, fpointer adlý göstericinin gösterdiði dosyanýn içine, istenen deðerlerin yazýlmasýný saðladýk.
	fprintf(fpointer,"%i %s %s %s %s %i\n\n",kitapEklemeBilgileri.kitap_id, kitapEklemeBilgileri.kitap_adi, kitapEklemeBilgileri.yazar_adi, kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
	fclose(fpointer);   // fclose() fonksiyonu ile dosyayý kapattýk.
	// --------- // Kitap Kayit Sonu
	system("cls");
	yerxy(30,8);
	printf("Kitap Basarili Bir Sekilde Kaydedildi");	
	yerxy(30,11);
	printf("Baska Bir Kitap Kayit Etmek Istiyor Musunuz:");
	yerxy(30,13);
	printf("Kayida Devam Etmek Icin 1, Cikis Icin 0");
	yerxy(30,15);
	
	
	do{
	switch (getch()){
		case '1':{
			kitap_ekleme();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);
	
}






// KÝTAP DÜZENLEME
void kitap_duzenleme()
{
  int i,bulundu,duzenlenecekKitap_id,cikis;
  char ch;
  int kitap_id;
  FILE *fpointer, *duzenleme;  // Düzenleme için iki dosyaya ihtiyacýmýz olduðundan,
  system("cls");			   // iki tane pointer tanýmladýk.
  	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******    KITAP DUZENLEME EKRANINA HOS GELDINIZ    ******");
	yerxy(30,5);
	printf("*********************************************************");

   fpointer=fopen("kitapKayit.txt","rb+");  // Ýlk dosyayý açtýk.
   if(fpointer==NULL)
   {
   		yerxy(30,7);
		printf("Dosya Acma Islemi Basarisiz");
		getch();
		ana_menu();
   }
   yerxy(30,9);
   printf("Duzenlenecek Kitabin ID'sini Giriniz");
   scanf("%i",&duzenlenecekKitap_id);
   yerxy(30,11);
   duzenleme=fopen("geciciKayit.txt","a+");  // Ýkinci dosyayý açtýk.
   if (duzenleme==NULL)
   {
   	yerxy(30,13);
   	printf("Dosya Acma Islemi Basarisiz");
	yerxy(30,14);   	
   	printf("Ana Menuye Donmek Icin Bir Tusa Basiniz");
   	ana_menu();
   }
   else
   {
   	while(fscanf(fpointer,"%i %s %s %s %s %i\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
   	{
   		if(kitapEklemeBilgileri.kitap_id==duzenlenecekKitap_id)  // Düzenlenecek kitabýn ID'si ile, sistemdeki ID uyuþursa
   		{														 // düzenleme iþlemlerini baþlatmak için bir koþul oluþturduk.
   			bulundu=1;
   			yerxy(30,15);   
			printf("Ilgili Kitap Kutuphanede Bulundu. Duzenleme Islemine Baslayabilirsiniz!");
			yerxy(30,17);   
			printf("Duzenleme Islemine Baslamak Icin 1'e basiniz - Ana Menu Icin 0'a basiniz");
			
			// KARAR DÖNGÜSÜ
			do{
			switch (getch()){
			case '1':{			
			cikis = 3;
			system("cls");
			break;
			}
			case '0':{
			ana_menu();
			cikis = 3;
			break;
			}
			default: cikis = 4;
			}
			}while (cikis != 3);
			
			
   			do
			{	
			yerxy(30,11);
			printf("ADIM 1");
			yerxy(30,13);
			printf("ONEMLI VERILERI GIRINIZ:");
			yerxy(30,15);
			printf("------------------------------");
			yerxy(30,17);
			printf("Kitap Adi: ");
			fflush(stdin);		
			gets(kitapEklemeBilgileri.kitap_adi);
			system("cls");
			kitapEklemeBilgileri.kitap_adi[0]=toupper(kitapEklemeBilgileri.kitap_adi[0]);
			for (i=0;i<strlen(kitapEklemeBilgileri.kitap_adi); ++i)
			{
			if(isalpha(kitapEklemeBilgileri.kitap_adi[i]))
			{
				uyum = 1;
			}
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{	
			yerxy(30,8);
			printf("!Kitabin Adi Sayi Iceremez!");
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 2");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ:");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Yazar Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.yazar_adi);
		system("cls");
		kitapEklemeBilgileri.yazar_adi[0]=toupper(kitapEklemeBilgileri.yazar_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.yazar_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.yazar_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("!Yazarin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
	do
	{
		yerxy(30,11);
		printf("ADIM 3");
		yerxy(30,13);
		printf("ONEMLI VERILERI GIRINIZ:");
		yerxy(30,15);
		printf("------------------------------");
		yerxy(30,17);
		printf("Alan Kisinin Adi: ");
		fflush(stdin);
		gets(kitapEklemeBilgileri.aKisi_adi);
		system("cls");
		kitapEklemeBilgileri.aKisi_adi[0]=toupper(kitapEklemeBilgileri.aKisi_adi[0]);
		for (i=0;i<strlen(kitapEklemeBilgileri.aKisi_adi); ++i)
		{
			if(isalpha(kitapEklemeBilgileri.aKisi_adi[i]))
				uyum = 1;
			else
			{
				uyum = 0;
				break;
			}
		}
		if (!uyum)
		{
			yerxy(30,8);
			printf("Alan Kisinin Adi Sayi Iceremez!");
			
		}
	}while(!uyum);
		do
			{
				yerxy(30,11);
				printf("ADIM 4");
				yerxy(30,13);
				printf("ONEMLI VERILERI GIRINIZ:");
				yerxy(30,15);
				printf("------------------------------");
				yerxy(30,17);
				printf("Kitap Turu:");
				fflush(stdin);
				gets(kitapEklemeBilgileri.kitapTur);
				system("cls");
				kitapEklemeBilgileri.kitapTur[0]=toupper(kitapEklemeBilgileri.kitapTur[0]);
				for (i=0;i<strlen(kitapEklemeBilgileri.kitapTur); ++i)
				{
					if(isalpha(kitapEklemeBilgileri.kitapTur[i]))
					uyum = 1;
					else
					{
						uyum = 0;
						break;
					}
				}
				if (!uyum)
				{
					yerxy(30,8);
					printf("!Kitabin Turu Sayi Iceremez!");
					
				}
			}while(!uyum);			
			
			kitapEklemeBilgileri.gun = 0;

			// Düzenlenen kitabýn bilgilerini, duzenleme adlý göstericinin gösterdiði dosyanýn içine yazdýk.
			fprintf(duzenleme,"%i %s %s %s %s %i",kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
			fflush(stdin);
			yerxy(30,8);
			printf("Kitap Bilgileri Guncellemesi Kaydedildi");
			
	   }
	   yerxy(30,15);
	   if(!bulundu)printf("Boyle Bir Kitap Bulunmamaktadir");
	   fclose(duzenleme); // Ýki dosyayý da kapattýk.
	   fclose(fpointer);
	   remove("kitapKayit.txt");  // ÝLk dosyayý sildik.
	   rename("geciciKayit.txt","kitapKayit.txt");  // Ýkinci dosyanýn adýný birinci dosyanýn adý yaptýk. 
	  
    	
   }
}
		yerxy(30,25);	
		printf("Kitap Duzenlemeye Devam Etmek Icin 1 / Cikis Icin 0");
		yerxy(30,26);	
		
		do{
		switch (getch()){
		case '1':{
			kitap_duzenleme();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);	
}





// KÝTAP SÝLME
void kitap_silme()
{
	
	int silinecekKitap_id,bulundu;
	system("cls");
	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******      KITAP SILME EKRANINA HOS GELDINIZ      ******");
	yerxy(30,5);
	printf("*********************************************************");
	FILE *fpointer,*fpointer2;     // Yine ikinci dosyaya ihtiyacýmýz olduðu için iki tane pointer tanýmladýk.
	fpointer=fopen("kitapKayit.txt","r");  // Birinci dosyayý açtýk.
	yerxy(30,9);
	printf("Silinecek Kitabin Id'sini Giriniz: ");
	scanf("%i",&silinecekKitap_id);
	fpointer2=fopen("geciciKayit.txt","w+");  // Ýkinci dosyayý açtýk.
	if(fpointer==NULL)
	{
		yerxy(30,11);
		printf("Boyle Bir Kitap Bulunmamaktadir!");
		yerxy(30,13);
		printf("Ana Menuye Yonlendiriliyorsunuz");		
		ana_menu();
	}
	else
	{
		while(fscanf(fpointer,"%i %s %s %s %s %i\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
		{
			if(silinecekKitap_id!=kitapEklemeBilgileri.kitap_id)
			{
				fprintf(fpointer2,"%i %s %s %s %s %i\n",kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
			}
			else
			{
				bulundu=1;
			}
		}
		if(!bulundu)
		{
			yerxy(30,11);
			printf("Boyle Bir Kitap Bulunmamaktadir!");
		}
		else
		{
			yerxy(30,13);
			printf("Silme Islemi Basari Ile Gerceklestirildi");
		}
		fclose(fpointer);   // Birinci dosyayý kapattýk.
		fclose(fpointer2);	// Ýkinci dosyayý kapattýk.
		remove("kitapKayit.txt"); // Birinci dosyayý sildik.
		rename("geciciKayit.txt","kitapKayit.txt");  // Ýkinci dosyanýn adýný birinci dosyanýn adý yaptýk.
	}
	getch();
	ana_menu();
}




// KÝTAP ÖDÜNÇ ALMA
void kitap_odunc_alma()
{
  	int i,bulundu,oduncKitap_id,cikis;
  	char ch;
  	int kitap_id;
  	FILE *fpointer, *duzenleme;  // Ýki dosyaya ihtiyacýmýz olduðundan dolayý iki tane pointer tanýmladýk.
  	system("cls");
  	yerxy(30,1);
	printf("*********************************************************");
	yerxy(30,3);
	printf("******    KITAP ODUNC ALMA EKRANINA HOS GELDINIZ    *****");
	yerxy(30,5);
	printf("*********************************************************");

   fpointer=fopen("kitapKayit.txt","rb+");  // Ýlk dosyayý açtýk.
   if(fpointer==NULL)
   {
   		yerxy(30,10);
		printf("Dosya acma islemi basarisiz");
		yerxy(30,12);
		printf("Ana Ekrana Yonlendiriliyorsunuz");	
		yerxy(30,14);
		printf("Herhangi Bir Tusa Basiniz");
		getch();	
		ana_menu();
   }
   yerxy(30,9);
   printf("Odunc Alinacak Kitabin ID'sini Giriniz ");
   scanf("%i",&oduncKitap_id);    // Kullanýcýdan ödünç alýnacak kitabýn ID'sini aldýk.
   yerxy(30,11);
   duzenleme=fopen("geciciKayit.txt","a+"); // Ýkinci dosyayý açtýk.
   if (duzenleme==NULL)
   {
   	yerxy(30,13);
   	printf("Dosya Acma Islemi Basarisiz");
	yerxy(30,14);   	
   	printf("Ana Menuye Donmek Icin Bir Tusa Basiniz");
   	ana_menu();
   }
   else
   {
   	while(fscanf(fpointer,"%i %s %s %s %s %i\n",&kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,&kitapEklemeBilgileri.gun)!=EOF)
   	{
   		if(kitapEklemeBilgileri.kitap_id==oduncKitap_id)  // Dosyada ödünç alýnacak kitapla ayný ID'de bir kitap varsa
   		{												  // bu koþul çalýþtý.
   			bulundu=1;
   			yerxy(30,15);   
			printf("Ilgili Kitap Kutuphanede Bulundu. Odunc Alma Islemine Baslayabilirsiniz!");
			yerxy(30,17);   
			printf("Odunc Alma Islemine Baslamak Icin 1'e basiniz - Ana Menu Icin 0'a basiniz");
			
			// KARAR DÖNGÜSÜ
			do{
			switch (getch()){
			case '1':{			
			cikis = 3;
			system("cls");
			break;
			}
			case '0':{
			ana_menu();
			cikis = 3;
			break;
			}
			default: cikis = 4;
			}
			}while (cikis != 3);
				
			
			yerxy(30,17);
			printf("Kitabi Kac Gun Almak Istediginizi Giriniz\n");
			
			do
			{
				yerxy(30,11);
				printf("ADIM 1");
				yerxy(30,13);
				printf("ONEMLI VERILERI GIRINIZ:");
				yerxy(30,15);
				printf("------------------------------");
				yerxy(30,19);
				printf("En fazla 30 gune kadar kitabi odunc alabilirsiniz\n");
				yerxy(30,21);
				printf("Karar: ");
				scanf("%i",&kitapEklemeBilgileri.gun);  // Kullanýcýdan kitabý kaç günlüðüne ödünç almak istediðini
				system("cls");							// aldýk.
				if(kitapEklemeBilgileri.gun<1 || kitapEklemeBilgileri.gun>30)
				{
					yerxy(30,8);
					printf("!30 Gunden Fazla Alamazsin!");
					
				}
			}while(kitapEklemeBilgileri.gun<1 || kitapEklemeBilgileri.gun>30);    // En fazla 30 günlüðüne kitap ödünç alýnabildiði için,
																				  // 30 günden fazla veya 1 günden az deðer girilirse
																				  // döngü yeniden çalýþýr
				// Düzenlenen kitabýn bilgilerini ikinci dosyaya yazdýrdýk. 
				fprintf(duzenleme,"%i %s %s %s %s %i",kitapEklemeBilgileri.kitap_id,kitapEklemeBilgileri.kitap_adi,kitapEklemeBilgileri.yazar_adi,kitapEklemeBilgileri.aKisi_adi,kitapEklemeBilgileri.kitapTur,kitapEklemeBilgileri.gun);
				fflush(stdin);
				yerxy(30,8);
				printf("Kitap Bilgileri Guncellemesi Kaydedildi");
			
	   }
	   yerxy(30,15);
	   if(!bulundu)printf("Boyle Bir Kitap Bulunmamaktadir");  // Eðer girilen ID, sistemdeki ID ile uyuþmazsa, 
	   														   // bu koþul çalýþýr
	   fclose(duzenleme); // Ýkinci dosyayý kapattýk
	   fclose(fpointer);  // Birinci dosyayý kapattýk
	   remove("kitapKayit.txt");  // Ýlk dosyayý sildik.
	   rename("geciciKayit.txt","kitapKayit.txt");  // Ýkinci dosyanýn adýný birinci dosyanýn adýyla deðiþtirdik.
	  
    	
   }
}
		yerxy(30,12);	
		printf("Kitap Odunc Almaya Devam Etmek Icin 1 / Cikis Icin 0");
		yerxy(30,14);	
		
		do{
		switch (getch()){
		case '1':{
			kitap_odunc_alma();
			cikis = 3;
			break;
		}
		case '0':{
			ana_menu();
			cikis = 3;
			break;
		}
		default: cikis = 4;
	}
	}while (cikis != 3);	
}

