/** @file main.c
  * @description Bir psikoloðun randevu defteri.
  * @assignment Odev 2
  * @date 26.12.2019
  * @author Halil Ýbrahim Yarýþ / halilibrahim.yaris34@stu.fsm.edu.tr
  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "randevuOps.h"
typedef enum
{
    false,
    true
} boolean;
boolean cikisYap2(boolean);
boolean kelimeMi2(char[]);
boolean sayiMi2(char[]);
void main()
{
    Hasta h;
    Randevu r;
    //randevulariYazdir(&h, &r);
    //randevuAraAd();
    //randevuAraGun();
    //randevuEkle();

    char kullaniciGirisi[30];
    int giris;
    int giris2;
    boolean devam = true;
    boolean devam2 = true;
    while (devam == true) //devam ifadesi true olana kadar menüden cikilmayacaktir.
    {

        printf("Yapilacak islemi seciniz\n");
        printf("1.Randevulari Listele\n");
        printf("2.Randevulari Ara\n");
        /*printf("2.1 Ada Gore Ara\n");
        printf("2.2 Gune Gore Ara\n");
        printf("2.3 Ana Menuye Geri Don\n");*/
        printf("3. Randevu ver\n");
        printf("4. Randevu Sil\n");
        printf("5.Exit\n");
        printf("islem no:");
        gets(kullaniciGirisi);

        if (sayiMi2(kullaniciGirisi) == false || atoi(kullaniciGirisi) < 1 || atoi(kullaniciGirisi) > 5)
        {
            printf("Lutfen girdiginiz sayiyi kontrol ediniz.Girdiginiz deger sayi olmali ve 5 ten buyuk olmamali\n");
            //menuyuGetir(kullaniciGirisi);
            printf("Lutfen yapmak istediginiz islemi seciniz:");
            gets(kullaniciGirisi);
        }
        giris = atoi(kullaniciGirisi);
        if (giris == 1)
        {
            randevulariYazdir(&h, &r);
        }
        if (giris == 2)
        {
            char kullaniciGirisi2[30];
            while (devam2 == true) //alt menu devam2 ifadesi false olana kadar dönecektir.
            {
                printf("1.Ada Gore Ara\n");
                printf("2.Gune Gore Ara\n");
                printf("3.Ana Menuye Geri Don\n");
                printf("Lutfen yapmak istediginiz islemi seciniz:");
                gets(kullaniciGirisi2);

                if (sayiMi2(kullaniciGirisi) == false || atoi(kullaniciGirisi) < 1 || atoi(kullaniciGirisi) > 3)
                {
                    printf("Lutfen girdiginiz sayiyi kontrol ediniz.Girdiginiz deger sayi olmali ve 3 ten buyuk olmamali");
                    //menuyuGetir(kullaniciGirisi);
                    printf("Lutfen yapmak istediginiz islemi seciniz:");
                    gets(kullaniciGirisi2);
                }
                giris2 = atoi(kullaniciGirisi2);
                if (giris2 == 1)
                {
                    randevuAraAd();
                }
                if (giris2 == 2)
                {
                    randevuAraGun();
                }

                if (giris2 == 3)
                {
                    devam2 = cikisYap2(devam2);
                    printf("Arama menusunden ciktiniz\n");
                }
            }
            devam2 = true;
        }
        if (giris == 3)
        {
            randevuEkle();
        }
        if (giris == 4)
        {
            randevuSil();
        }

        if (giris == 5)
        {
            devam = cikisYap2(devam);
            printf("programdan ciktiniz");
        }
    }
}

boolean cikisYap2(boolean d)
{
    return !d;
}
boolean sayiMi2(char deger[])
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
boolean kelimeMi2(char deger[])
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
