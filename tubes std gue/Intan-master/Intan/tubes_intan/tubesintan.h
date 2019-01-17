#ifndef TUBESINTAN_H_INCLUDED
#define TUBESINTAN_H_INCLUDED

#include <cstddef>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstring>


#define nil NULL

using namespace std;

typedef struct elmlist_orang *address_orang;
typedef struct elmlist_pendidikan *address_pendidikan;
typedef struct elmlist_ambil *address_ambil;

//variabel Type untuk type infotype
struct type_tanggal_lahir
{
    string tanggal;
    string bulan;
    string tahun;
};

//Semua Infotype Program
struct infotype_orang{
    int id;
    string nama;
    type_tanggal_lahir tanggallahir;
};

struct infotype_pendidikan{
    string singkatan;
    string kepanjangan;
    int id;
};

struct infotype_ambil{
    int id_orang;
    int id_pendidikan;
};

//Semua elemen list program
struct elmlist_orang{
    infotype_orang info;
    address_orang next;
    address_orang prev;
};

struct elmlist_pendidikan{
    infotype_pendidikan info;
    address_pendidikan next;
};

struct elmlist_ambil{
    infotype_ambil info;
    address_ambil next;
    address_ambil prev;
};

//Semua list program
struct list_orang{
    address_orang first;
    address_orang last;
};

struct list_pendidikan{
    address_pendidikan first;
};

struct list_ambil{
    address_ambil first;
    address_ambil last;
};

//struktur data utama
struct atur{
    infotype_ambil IA;
    infotype_orang IO;
    infotype_pendidikan IP;
    address_ambil AA;
    address_orang AO;
    address_pendidikan AP;
    list_ambil LA;
    list_orang LO;
    list_pendidikan LP;
};

struct setting_menu{
    int menu;
    int loop_id_orang;
    int loop_id_pendidikan;
    string word;
    int loop_cari;
    int loop_cari2;
    infotype_orang nampung [100];
};

void system_setting();
void menu();

void create_list_dll(list_orang &LO);
address_orang alokasi_dll(infotype_orang data);
void dealokasi_dll(address_orang AO);
void insert_orang (setting_menu &SM, atur &A);
void insert_first_dll(list_orang &LO, address_orang AO);
void view_list_dll(list_orang LO);
void print_orang (setting_menu &SM, atur &A);

void create_list_sll(list_pendidikan &LP);
address_pendidikan alokasi_sll(infotype_pendidikan data);
void insert_pendidikan (setting_menu &SM, atur &A);
void insert_last_sll(list_pendidikan &LP,address_pendidikan AP);
void delete_after_sll(list_pendidikan &LP, address_pendidikan AP);
void view_list_sll(list_pendidikan LP);
void print_pendidikan (setting_menu &SM, atur &A);

void create_list_cdll(list_ambil &LA);
address_ambil alokasi_cdll(infotype_ambil data);
void dealokasi_cdll(list_ambil LA, address_ambil AA);
void insert_after_cdll(list_ambil &LA, address_ambil AA);
void delete_first_cdll(list_ambil &LA, address_ambil AA);
void delete_last_cdll(list_ambil &LA, address_ambil AA);
void view_list_cdll(list_ambil LA);
void print_relasi (setting_menu &SM, atur &A);

void pilihanbaru(setting_menu &SM, atur &A);
void insert_menu(setting_menu &SM, atur &A);
void insert_relasi (setting_menu &SM, atur &A);
void insert_relasi1 (setting_menu &SM, atur &A);
void insert_relasi2 (setting_menu &SM, atur &A);
void insert_relasi3 (setting_menu &SM, atur &A);
void insert_relasi4 (setting_menu &SM, atur &A);
void insert_relasi5 (setting_menu &SM, atur &A);
void insert_relasi6 (setting_menu &SM, atur &A);
void insert_relasi7 (setting_menu &SM, atur &A);
void delete_menu(setting_menu &SM, atur &A);
void update_menu(setting_menu &SM, atur &A);
void view_menu(setting_menu &SM, atur &A);
#endif // TUBESINTAN_H_INCLUDED
