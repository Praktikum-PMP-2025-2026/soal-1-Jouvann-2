/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3 - Structures and Dynamic Arrays
 *   Hari dan Tanggal    : Rabu, 28 April 2026
 *   Nama (NIM)          : Joe Steven Hardy (13224065)
 *   Nama File           : soal1.c
 *   Deskripsi           : Program memonitor performa pegawai berdasarkan shift kerja. Program menerima input data pegawai, termasuk nama, ID, shift kerja, dan skor performa. Program kemudian menentukan pegawai dengan skor tertinggi untuk setiap shift (PAGI, SIANG, MALAM) dan mencetak nama pegawai terbaik untuk setiap shift tersebut.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pegawai {
    char nama[50];
    int id;
    char shift[10];
    int skor;
} pegawai;

pegawai *dataPegawai = NULL;
pegawai *pegawaiTop = NULL;
int jumlahPegawai = 0;
// char tempNama[50], tempShift[10];
// int tempId,tempSkor;

char input[100];
char *token = NULL;
int counter = 0, idx = 0;

int countPagi = 0, countSiang = 0, countMalam = 0;

void ambilData(){
    fgets(input, 100, stdin);

    token = strtok(input, " ");

    while (token!= NULL){
        if (counter < 1){
            jumlahPegawai = atoi(token);
            dataPegawai = realloc(dataPegawai, jumlahPegawai * sizeof(pegawai));

            for (int i = 0; i < jumlahPegawai; i++){
                dataPegawai[i].nama[0] = '\0';
                dataPegawai[i].id = 0;
                dataPegawai[i].shift[0] = '\0';
                dataPegawai[i].skor = 0;
            }

            counter++;
        }
        else {
            if (counter % 4 == 1){
                strcpy(dataPegawai[idx].nama, token);
            }
            else if (counter % 4 == 2){
                dataPegawai[idx].id = atoi(token);
            }
            else if (counter % 4 == 3){
                strcpy(dataPegawai[idx].shift, token);
            }
            else if (counter % 4 == 0){
                dataPegawai[idx].skor = atoi(token);
                idx++; 
            }

            counter++;
        }
        token = strtok(NULL, " ");
    }
}

void rankShift(){
    pegawaiTop = realloc(pegawaiTop, 3 * sizeof(pegawai));
    
    for (int i = 0; i < jumlahPegawai; i++){
        if (strcmp(dataPegawai[i].shift, "PAGI") == 0){
            strcpy(pegawaiTop[0].nama, dataPegawai[i].nama);
            pegawaiTop[0].id = dataPegawai[i].id;
            strcpy(pegawaiTop[0].shift, dataPegawai[i].shift);
            pegawaiTop[0].skor = dataPegawai[i].skor;
            countPagi++;
        }
        if (strcmp(dataPegawai[i].shift, "SIANG") == 0){
            strcpy(pegawaiTop[1].nama, dataPegawai[i].nama);
            pegawaiTop[1].id = dataPegawai[i].id;
            strcpy(pegawaiTop[1].shift, dataPegawai[i].shift);
            pegawaiTop[1].skor = dataPegawai[i].skor;
            countSiang++;
        }
        if (strcmp(dataPegawai[i].shift, "MALAM") == 0){
            strcpy(pegawaiTop[2].nama, dataPegawai[i].nama);
            pegawaiTop[2].id = dataPegawai[i].id;
            strcpy(pegawaiTop[2].shift, dataPegawai[i].shift);
            pegawaiTop[2].skor = dataPegawai[i].skor;
            countMalam++;
        }
        if (countPagi > 0 && countSiang > 0 && countMalam > 0){
            break;
        }

    }

    for (int i=0; i < jumlahPegawai; i++){
        for (int j=0; j < jumlahPegawai; j++){

            if (i == j){
                continue;
            }
            if (strcmp(dataPegawai[i].shift, dataPegawai[j].shift) == 0){
                if (dataPegawai[j].skor > dataPegawai[i].skor){
                     if (strcmp(dataPegawai[i].shift, "PAGI") == 0){
                        strcpy(pegawaiTop[0].nama, dataPegawai[j].nama);
                        pegawaiTop[0].id = dataPegawai[j].id;
                        strcpy(pegawaiTop[0].shift, dataPegawai[j].shift);
                        pegawaiTop[0].skor = dataPegawai[j].skor;
                    }
                    else if (strcmp(dataPegawai[i].shift, "SIANG") == 0){
                        strcpy(pegawaiTop[1].nama, dataPegawai[j].nama);
                        pegawaiTop[1].id = dataPegawai[j].id;
                        strcpy(pegawaiTop[1].shift, dataPegawai[j].shift);
                        pegawaiTop[1].skor = dataPegawai[j].skor;
                    }
                    else if (strcmp(dataPegawai[i].shift, "MALAM") == 0){
                        strcpy(pegawaiTop[2].nama, dataPegawai[j].nama);
                        pegawaiTop[2].id = dataPegawai[j].id;
                        strcpy(pegawaiTop[2].shift, dataPegawai[j].shift);
                        pegawaiTop[2].skor = dataPegawai[j].skor;
                    }
                }
                
                else if (dataPegawai[j].skor == dataPegawai[i].skor){
                    
                    if (dataPegawai[j].id < dataPegawai[i].id){
                        if (dataPegawai[i].shift == "PAGI"){
                            strcpy(pegawaiTop[0].nama, dataPegawai[j].nama);
                            pegawaiTop[0].id = dataPegawai[j].id;
                            strcpy(pegawaiTop[0].shift, dataPegawai[j].shift);
                            pegawaiTop[0].skor = dataPegawai[j].skor;
                        }
                        else if (dataPegawai[i].shift == "SIANG"){
                            strcpy(pegawaiTop[1].nama, dataPegawai[j].nama);
                            pegawaiTop[1].id = dataPegawai[j].id;
                            strcpy(pegawaiTop[1].shift, dataPegawai[j].shift);
                            pegawaiTop[1].skor = dataPegawai[j].skor;
                        }
                        else if (dataPegawai[i].shift == "MALAM"){
                            strcpy(pegawaiTop[2].nama, dataPegawai[j].nama);
                            pegawaiTop[2].id = dataPegawai[j].id;
                            strcpy(pegawaiTop[2].shift, dataPegawai[j].shift);
                            pegawaiTop[2].skor = dataPegawai[j].skor;
                        }
                    }
                    else if (dataPegawai[j].id == dataPegawai[i].id){
                        if (strcmp(dataPegawai[j].nama, dataPegawai[i].nama) < 0){
                            if (dataPegawai[i].shift == "PAGI"){
                                strcpy(pegawaiTop[0].nama, dataPegawai[j].nama);
                                pegawaiTop[0].id = dataPegawai[j].id;
                                strcpy(pegawaiTop[0].shift, dataPegawai[j].shift);
                                pegawaiTop[0].skor = dataPegawai[j].skor;
                            }
                            else if (dataPegawai[i].shift == "SIANG"){
                                strcpy(pegawaiTop[1].nama, dataPegawai[j].nama);
                                pegawaiTop[1].id = dataPegawai[j].id;
                                strcpy(pegawaiTop[1].shift, dataPegawai[j].shift);
                                pegawaiTop[1].skor = dataPegawai[j].skor;
                            }
                            else if (dataPegawai[i].shift == "MALAM"){
                                strcpy(pegawaiTop[2].nama, dataPegawai[j].nama);
                                pegawaiTop[2].id = dataPegawai[j].id;
                                strcpy(pegawaiTop[2].shift, dataPegawai[j].shift);
                                pegawaiTop[2].skor = dataPegawai[j].skor;
                            }
                        }
                    
                    }       
                }
            }
        }
    }
}

int main(){
    ambilData();
    rankShift();

    // printf("Jumlah Pegawai: %d\n\n", jumlahPegawai);
    // for (int i = 0; i < jumlahPegawai; i++){
    //     printf("Nama : %s\n", dataPegawai[i].nama);
    //     printf("ID   : %d\n", dataPegawai[i].id);
    //     printf("Shift: %s\n", dataPegawai[i].shift);
    //     printf("Skor : %d\n\n", dataPegawai[i].skor);
    // }

    for (int i = 0; i < 3; i++){
        // printf("Top Pegawai Shift %s: %s\n", pegawaiTop[i].shift, pegawaiTop[i].nama);
        if (i == 0){
            if (countPagi != 0){
                printf("%s %s %d %d\n", pegawaiTop[i].shift, pegawaiTop[i].nama, pegawaiTop[i].id, pegawaiTop[i].skor);
            }
            if (countPagi == 0){
                printf("%s -\n", "PAGI");
            }
            
        }
        if (i == 1){
            if (countSiang != 0){
                printf("%s %s %d %d\n", pegawaiTop[i].shift, pegawaiTop[i].nama, pegawaiTop[i].id, pegawaiTop[i].skor);
            }
            if (countSiang == 0){
                printf("%s -\n", "SIANG");
            }
        }
        if (i == 2){
            if (countMalam != 0){
                printf("%s %s %d %d", pegawaiTop[i].shift, pegawaiTop[i].nama, pegawaiTop[i].id, pegawaiTop[i].skor);
            }
            if (countMalam == 0){
                printf("%s -", "MALAM");
            }
        }
    }

    return 0;
}
