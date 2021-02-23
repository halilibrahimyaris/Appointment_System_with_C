/** @file RandevuOps.c
  * @description Bir psikoloðun randevu defteri.
  * @assignment Odev 2
  * @date 26.12.2019
  * @author Halil Ýbrahim Yarýþ / halilibrahim.yaris34@stu.fsm.edu.tr
  */

#ifndef MATRIXOPS_H
#define MATRIXOPS_H

typedef struct hasta //her iki classta da kullanabilmek icin struct yapilari header file da tanimlanmistir.
{
    char isim[30];
    char soyisim[30];

} Hasta;
typedef struct randevu
{
    int saat;
    int gun;
} Randevu;
//fonksiyonlarin prototipleri tanimlanmistir.
void randevulariYazdir();
void randevuAraAd();
void randevuAraGun();
void randevuEkle();
void randevuSil();
void menuyuGetir(char[]);
int newCompareTo(char[], char[]);
int boyutStr(char[]);
#endif
