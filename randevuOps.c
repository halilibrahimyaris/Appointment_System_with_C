/** @file RandevuOps.c
  * @description Bir psikoloðun randevu defteri.
  * @assignment Odev 2
  * @date 26.12.2019
  * @author Halil Ýbrahim Yarýþ / halilibrahim.yaris@stu.fsm.edu.tr
  */

#include <stdio.h>
#include <stdlib.h>
#include "randevuOps.h"
#include <ctype.h>

typedef enum // bu enum boolean operatorleri projede kullanýlmasý icin yazilmistir.
{
    false,
    true
} boolean;
boolean cikisYap(boolean); // bu alanda kullanýlan fonksiyonlarin prototipleri tanimlasmistir
void randevulariYazdir();
void randevuAraAd();
void randevuAraGun();
void randevuEkle();
void randevuSil();
void menuyuGetir(char[]);
boolean sayiMi(char[]);
boolean kelimeMi(char[]);
int newCompareTo(char[], char[]);
int boyutStr(char[]);

boolean cikisYap(boolean d)
{
    return !d;
}

void randevulariYazdir() //bu metod .txt dosyasýndaki tüm randevularin listelenmesi icin yazilmistir
{
    Hasta hasta;
    Randevu randevu;
    FILE *fp;
    if ((fp = fopen("randevular.txt", "r")) == NULL) //sadece okuma yapildigi icin r modunda dosya acilmistir
    {
        printf("Dosya acilamadi\n"); //dosyanin acilip acilmadiginin kontroludur.
    }
    else
    {

        while (!feof(fp)) // dosyanýýn sonuna gelinceye kadar degeleri okuyup ilgili parametlerelere atayan ve onlari print eden kisim
        {

            fscanf(fp, "%[^,],%d,%d", hasta.isim, &randevu.gun, &randevu.saat);
            printf("\n");
            printf("Hasta Adi ve Soyadi : %s", hasta.isim);
            printf("\n");
            printf("Randevu Gunu: %d", randevu.gun);
            printf("\n");
            printf("Randevu Saati: %d", randevu.saat);
            printf("\n");
        }
    }
    fclose(fp); //dosyanýn kapanma komutu
}

void randevuAraAd() //bu fonksiyon kullanicinin girdigi isim degerine gore arama yapip onu getiren fonksiyondur.
{
    FILE *fp;
    Hasta hasta;
    Randevu randevu;
    char isim[30];
    printf("Lutfen arama yapilacak ismi giriniz:");
    gets(isim);
    if ((fp = fopen("randevular.txt", "r")) == NULL) // dosya sadece okuma yapildigi icin r modunda dosya acilmistir
    {
        printf("Dosya acilamadi\n");
    }
    else
    {
        boolean varMi = false;
        while (!feof(fp))
        {
            fscanf(fp, "%s %s", hasta.isim, hasta.soyisim);
            if (newCompareTo(hasta.isim, isim) == 1) //girilen isimle dosyadaki isimi karsilatrien  if yapýsý
            {
                printf("%s %s \n", hasta.isim, hasta.soyisim);
                varMi = true;
            }
            else if (kelimeMi(isim) == false) //girilen ifadenin kelime olup olmadigini karsilatiran if yapisi
            {
                printf("Arama yapilabilmesi icin girilen degerin karakter olmasi gerekir.\n");
                break;
                printf("Lutfen arama yapilacak ismi giriniz:");
                gets(isim);
            }
        }
        if (varMi == false)
        {
            printf("Aranan isimde hasta bulunamadi\n");
        }
    }
    fclose(fp);
}

void randevuAraGun() //bu fonksiyon kullanicinin girdigi gun degerine gore arama yapip onu getiren fonksiyondur.
{
    FILE *fp;
    Hasta hasta;
    Randevu randevu;
    char gun[30];
    int randevuGunu;
    boolean varMi = false;
    printf("Lutfen arama yapilacak gunu giriniz:");
    scanf("%s", gun);
    if ((fp = fopen("randevular.txt", "r")) == NULL) // dosya sadece okuma yapildigi icin r modunda dosya acilmistir
    {
        printf("Dosya acilamadi\n");
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%[^,],%d,%d", hasta.isim, &randevu.gun, &randevu.saat);
            if (sayiMi(gun) == false) //girilen degerin sayi olup olmadigini gösteren if ifadesi
            {
                printf("Arama yapabilmek icin girdiginiz degerler sayi olmali\n");
                printf("Lutfen arama yapilacak gunu giriniz:");
                scanf("%s", gun);
            }
            randevuGunu = atoi(gun);
            if (randevuGunu > 7)
            {
                printf("Arama yapabilmek icin girdiginiz degerler 7 den buyuk olmamali\n"); //sayi araligini kontrol eden bölüm
                printf("Lutfen arama yapilacak gunu giriniz:");
                scanf("%s", gun);
            }

            else if (randevuGunu == randevu.gun)
            {
                printf("%s ,%d,%d\n", hasta.isim,randevu.gun, randevu.saat);
                varMi = true;
            }
            
        }
		if (varMi == false)
		{
		    printf("Randevu bulunamadi");
		}
        fclose(fp);
    }
}
void randevuEkle() //bu foksiyon kullanicidan alinan bilgiler dogrultusunda dosyaya randevu ekleyen metoddur.
{
    FILE *fp;
    Hasta hasta;
    Randevu randevu;
    int randSaat;
    int randGun;
    char gun[12];
    char saat[12];
    char ad[30];
    char soyad[30];
    printf("Lutfen hastanin adini giriniz:");
    gets(ad);
    if (kelimeMi(ad) == false) //girilen ifadenin kelime olup olmadigini karsilatiran if yapisi
    {
        printf("Girdiginiz isim rakam yahut baska karakter icermemeli\n");
        printf("Lutfen hastanin adini giriniz:");
        gets(ad);
    }

    printf("Lutfen hastanin soyadini giriniz:");
    gets(soyad);
    if (kelimeMi(soyad) == false)
    {
        printf("Girdiginiz soyisim rakam yahut baska karakter icermemeli\n"); //girilen ifadenin kelime olup olmadigini karsilatiran if yapisi
        printf("Lutfen hastanin soyadini giriniz:");
        gets(soyad);
    }

    printf("Lutfen randevu gunun giriniz:");
    gets(gun);
    while (sayiMi(gun) == false)
    {
        printf("Girdiginiz gun degeri harf yahut baska karakter icermemeli\n"); //girilen degerin sayi olup olmadigini gösteren if ifadesi
        printf("Lutfen randevu gunun giriniz:");
        gets(gun);
    }
    randGun = atoi(gun);
    while (randGun < 1 || randGun > 8) //sayi araligini kontrol eden bölüm
    {

        printf("Randevu gunu 7 den buyuk olamaz\n");
        printf("Lutfen randevu gunun giriniz:");
        gets(gun);
        randGun = atoi(gun);
    }
    randGun = atoi(gun);

    printf("Lutfen randevu saatini giriniz:");
    gets(saat);
    if (sayiMi(saat) == false) //girilen degerin sayi olup olmadigini gösteren if ifadesi
    {
        printf("Girdiginiz gun degeri harf yahut baska karakter icermemeli\n");
        printf("Lutfen randevu saatini giriniz:");
        gets(saat);
    }
    randSaat = atoi(saat);
    while (randSaat < 8 || randSaat > 18) //sayi araligini kontrol eden bölüm
    {
        printf("Mesai saatleri disinda randevu saati belirlenemez\nMESAI SAATLERI SABAH 9 ILE AKSAM 17 ARASINDADIR\n");
        printf("Lutfen randevu saatini giriniz:");
        gets(saat);
        randSaat = atoi(saat);
    }
    randSaat = atoi(saat);
    boolean ayni = false;
    if ((fp = fopen("randevular.txt", "r")) == NULL) // bu kýsým ayný saatte ve ayný günde randevu olup oladigini kontrol ediyor.
    {
        printf("Dosya acilamadi\n");
    }

    while (!feof(fp))
    {
        fscanf(fp, "%[^,],%d,%d", hasta.isim, &randevu.gun, &randevu.saat);
        if ((randGun == randevu.gun && randSaat == randevu.saat))
        {
            printf("Belirlediginiz tarih yeni randevu icin uygun degildir\n");
            ayni = true;
            //randevuEkle();
        }
        else if (!(randGun == randevu.gun && randSaat == randevu.saat))
        {
            ayni = false;
        }
    }

    fclose(fp);
    if (ayni == false)
    { //bu kýsým eger ayný gun ve saate randevu yoksa girilen randevuyu dosyaya yazan kisimdir.
        if ((fp = fopen("randevular.txt", "a")) == NULL)
        {
            printf("Dosya acilamadi\n");
        }
        else
        {
            randevu.gun = randGun;
            randevu.saat = randSaat;
            fprintf(fp, "\n%s %s,%d,%d", ad, soyad, randevu.gun, randevu.saat);
            printf("Randevu basarili bir sekilde  olusturulmustur.\n");
            ayni = true;
        }
    }
    fclose(fp);
}

void randevuSil() //bu fonksiyon adi girilen hastaya ait randevu bilgilerini silen fonksiyondur.
{
    FILE *fp;
    FILE *fp2;
    Hasta hasta;
    Randevu randevu;
    int silinen = 0;
    int okunan = 0;
    int yazilan = 0;
    boolean silindiMi=false;
    char hastaAd[30];
    if ((fp = fopen("randevular.txt", "r")) == NULL)
    {
        printf("Dosya acilamadi\n");
        exit(1);
    }
    if ((fp2 = fopen("geciciRand.txt", "w")) == NULL)
    {
        printf("Dosya 2 acilamadi\n");
        exit(1);
    }
    else
    {
        printf("Lutfen randevusunu silmek istediginiz hastanin adini giriniz:");
        gets(hastaAd);
        while (!feof(fp))
        {

            fscanf(fp, "%s %s\n", hasta.isim, hasta.soyisim);
            okunan++;

            if (newCompareTo(hasta.isim, hastaAd) == 0)
            {
                fprintf(fp2, "%s %s\n", hasta.isim, hasta.soyisim);
                yazilan++;
            }
            else
            {
                silinen = 1;
            }
            if (silinen && (okunan != yazilan))
            {
                printf("Aranan hasta silindi\n");
                silindiMi=true;
            }

        }
        if(silindiMi==false){
        	printf("Aranan hasta bulunamadi\n");
		}
    }

    fclose(fp);
    fclose(fp2);
    remove("randevular.txt");
    rename("geciciRand.txt", "randevular.txt");
}
boolean sayiMi(char deger[]) //girilen degerin sayi olup olmadgini kontol eden fonksiyon
{
    boolean sayi;
    sayi = true;
    int uzunluk, i;
    uzunluk = boyutStr(deger);

    for (i = 0; i < uzunluk; i++)
    {
        if (!isdigit(deger[i]))
        {
            printf("girdiginiz deger sayi degildir");
            sayi = false;
        }
    }

    return sayi;
}
boolean kelimeMi(char deger[]) //girilen degerin kelime olup olmadigini kontol eden fonksiyon
{
    boolean kelime;
    kelime = true;
    int uzunluk, i;
    uzunluk = boyutStr(deger);

    for (i = 0; i < uzunluk; i++)
    {
        if (!isalpha(deger[i]))
        {
            kelime = false;
        }
    }

    return kelime;
}

int newCompareTo(char arr1[], char arr2[]) //girilen iki stringi karsilastiran fonksiyon
{
    int i = 0;
    int boyutA = 0;
    int boyutB = 0;
    int j = 0;
    for (i = 0; arr1[i] != '\0'; i++)
    {
        boyutA++;
    }
    for (j = 0; arr2[j] != '\0'; j++)
    {
        boyutB++;
    }

    if (boyutA != boyutB)
    {
        return 0;
    }
    for (int a = 0; a < boyutA; a++)
    {
        if (arr1[a] != arr2[a])
        {
            return 0;
        }
        if (arr1[a] == arr2[a])
        {
            return 1;
        }
    }
}
int boyutStr(char arr[])
{ //stringin boyunu bulan fonskiyon
    int i = 0;
    int boyutA = 0;
    for (i = 0; arr[i] != '\0'; i++)
    {
        boyutA++;
    }
    return boyutA;
}
