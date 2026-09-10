#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <windows.h>

typedef char string[50];

void targetRasa();
void cetak(int kopi, float rasio, string gilingan, string suhu, int pembagianAwal, int pembagianAkhir);
int totalAir(int kopi, float rasio);
int bagianPertama(int kopi, float rasio);
int bagianKedua(int kopi, float rasio);
int tuang1(int kopi, float rasio, int pembagianAwal);
int tuang2(int kopi, float rasio, int pembagianAwal);
int tuang3(int kopi, float rasio, int pembagianAkhir);
int tuang4(int kopi, float rasio, int pembagianAkhir);
int finalTuang(int kopi, float rasio, int pembagianAwal, int pembagianAkhir);

int main(int argc, char const *argv[])
{
    int kopi, rasa;

    SetConsoleOutputCP(CP_UTF8);

    do
    {
        system("cls");
        printf("--- KALKULATOR SEDUH V60 ---");
        printf("\nMetode Tetsu Kasuya (Rasio 4:6)\n");
        do
        {
            printf("\nBerat Kopi (gram) : ");scanf("%d", &kopi);
            if(kopi < 10 || kopi > 30){
                printf("!! Kopi minimal 10 gram dan maksimal 30 gram !!\n");
            }
        } while (kopi < 10 || kopi > 30);
        
        targetRasa();
        printf("\nPilih target rasa : ");scanf("%d", &rasa);

        switch(rasa){
            case 1:{
                float rasio = 15.5;
                int pembagianAwal = 35, pembagianAkhir = 65;
                string gilingan = "Sedikit Halus";
                string suhu = "92°C - 94°C";
                cetak(kopi, rasio, gilingan, suhu, pembagianAwal, pembagianAkhir);
                break;
            }

            case 2:{
                float rasio = 16.5;
                int pembagianAwal = 65, pembagianAkhir = 35;
                string gilingan = "Sedikit Kasar";
                string suhu = "88°C - 91°C";
                cetak(kopi, rasio, gilingan, suhu, pembagianAwal, pembagianAkhir);
                break;
            }

            case 3:{
                float rasio = 16.0;
                int pembagianAwal = 50, pembagianAkhir = 50;
                string gilingan = "Pasir Kasar Standar";
                string suhu = "90°C - 92°C";
                cetak(kopi, rasio, gilingan, suhu, pembagianAwal, pembagianAkhir);
                break;
            }

            case 4:{
                float rasio = 14.5;
                int pembagianAwal = 40, pembagianAkhir = 60;
                string gilingan = "Halus";
                string suhu = "93°C - 96°C";
                cetak(kopi, rasio, gilingan, suhu, pembagianAwal, pembagianAkhir);
                break;
            }

            case 0:{
                system("cls");
                printf("--- Selamat Menyeduh ---");
                rasa = 0;
                break;
            }

            default:{
                printf("!! Menu Tidak Tersedia !!");
                break;
            }
        }
        getch();
    } while (rasa != 0);
    
    return 0;
}

void targetRasa(){
    printf("\n1. Lebih Manis");
    printf("\n2. Lebih Asam");
    printf("\n3. Seimbang");
    printf("\n4. Body Berat / Kuat");
    printf("\n0. Exit");
}

void cetak(int kopi, float rasio, string gilingan, string suhu,int pembagianAwal, int pembagianAkhir){
    printf("\n\n--- HASIL PERHITUNGAN ---");
    printf("\nTotal air : %d ml", totalAir(kopi, rasio));
    printf("\nRasio = 1 : %.1f", rasio);
    printf("\nUkuran Gilingan : %s", gilingan);
    printf("\nSuhu Air : %s", suhu);

    printf("\n\n--- TATA CARA TUANG ---");
    printf("\nTuang 1 (00:00 - 00:30) : %d ml", tuang1(kopi, rasio, pembagianAwal));
    printf("\nTuang 2 (00:45 - 01:15) : %d ml", tuang2(kopi, rasio, pembagianAwal));
    printf("\nTuang 3 (01:30 - 02:00) : %d ml", tuang3(kopi, rasio, pembagianAkhir));
    printf("\nTuang 4 (02:15 - selesai) : %d ml", finalTuang(kopi, rasio, pembagianAwal, pembagianAkhir));

    printf("\n\nWaktu target : ± 2:45 - 3:15 menit");
    printf("\nMetode 4:6 Tetsu Kasuya : 40%% air awal mengatur rasa, 60%% akhir mengatur kekuatan.");
    
    printf("\n\nTekan apa saja...");
    
}

int totalAir(int kopi, float rasio){
    int air = round(kopi * rasio);
    return air ;
}

int bagianPertama(int kopi, float rasio){
    return round(totalAir(kopi, rasio) * 0.40);
}

int bagianKedua(int kopi, float rasio){
    return round(totalAir(kopi, rasio) * 0.60);
}

int tuang1(int kopi, float rasio, int pembagianAwal){
    return round(bagianPertama(kopi, rasio) * (pembagianAwal / 100.0));
}

int tuang2(int kopi, float rasio, int pembagianAwal){
    return round(bagianPertama(kopi, rasio) * ((100 - pembagianAwal) / 100.0));
}

int tuang3(int kopi, float rasio, int pembagianAkhir){
    return round(bagianKedua(kopi, rasio) * (pembagianAkhir / 100.0));
}

int tuang4(int kopi, float rasio, int pembagianAkhir){
    return round(bagianKedua(kopi, rasio) * ((100 - pembagianAkhir) / 100.0));
}

int finalTuang(int kopi, float rasio, int pembagianAwal, int pembagianAkhir){
    int total = totalAir(kopi, rasio);

    int t1 = tuang1(kopi, rasio, pembagianAwal);
    int t2 = tuang2(kopi, rasio, pembagianAwal);
    int t3 = tuang3(kopi, rasio, pembagianAkhir);
    int t4 = tuang4(kopi, rasio, pembagianAkhir);

    if(t1 + t2 + t3 + t4 != total){
        return total - t1 - t2 - t3;
    }
    return t4;
}