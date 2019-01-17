#include "tubesintan.h"

void system_setting(){
    setting_menu SM;
    atur A;
    menu();

    SM.loop_id_orang = 0;
    SM.loop_id_pendidikan = 0;
    create_list_cdll(A.LA);
    create_list_dll(A.LO);
    create_list_sll(A.LP);
    pilihanbaru(SM,A);
}

void menu(){
    cout << "SELAMAT DATANG" << endl;
    cout << "DI APLIKASI DATA RIWAYAT PENDIDIKAN" << endl;
    system("PAUSE");
    system("CLS");
}
void pilihanbaru(setting_menu &SM, atur &A){
    cout << "Silahkan pilih menu yang anda inginkan :" << endl;
    cout << "1. Insert Data" << endl;
    cout << "2. Delete Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. View Data" << endl;
    cout << "5. EXIT" << endl;
    cout<<"Masukin pilihan anda :"<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {
            insert_menu(SM,A);
        }
        break;
    case 2 :
        {
            delete_menu(SM,A);
        }
    case 3 :
        {
            update_menu(SM,A);
        }
    case 4 :
        {
            view_menu(SM,A);
        }
    case '5' :
        {
            menu();
        }
    }
}

void insert_menu(setting_menu &SM, atur &A){
    cout << "Silahkan pilih menu yang anda inginkan :" << endl;
    cout << "1. Insert Orang" << endl;
    cout << "2. Insert Pendidikan" << endl;
    cout << "3. Insert Relasi" << endl;
    cout << "4. Back" << endl;
    cout<<"Masukin pilihan anda :"<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {
            insert_orang (SM,A);
            insert_menu(SM,A);
        }
        break;
    case 2 :
        {
            insert_pendidikan(SM,A);
            insert_menu(SM,A);
        }
        break;
    case 3 :
        {
            SM.menu = 1;
            insert_relasi(SM,A);
            insert_menu(SM,A);
        }
        break;
    case 4 :
        {
            pilihanbaru(SM,A);
        }
    }
}

void insert_orang (setting_menu &SM, atur &A){
    cout<<"SILAHKAN MASUKKAN DATA ANDA"<<endl;
    SM.loop_id_orang++;
    A.IO.id = SM.loop_id_orang;
    cout<<"Nama :"; cin>>A.IO.nama; cout<<endl;
    cout<<"Tanggal :"; cin>>A.IO.tanggallahir.tanggal; cout<<endl;
    cout<<"Bulan :"; cin>>A.IO.tanggallahir.bulan; cout<<endl;
    cout<<"Tahun :"; cin>>A.IO.tanggallahir.tahun; cout<<endl;
    A.AO = alokasi_dll(A.IO);
    insert_first_dll(A.LO,A.AO);
    view_list_dll(A.LO);

}

void insert_pendidikan (setting_menu &SM, atur &A){
    cout<<"SILAHKAN MASUKKAN DATA ANDA"<<endl;
    SM.loop_id_pendidikan++;
    A.IP.id = SM.loop_id_pendidikan;
    cout<<"Kepanjangan :"; cin>>A.IP.kepanjangan; cout<<endl;
    cout<<"Singkatan :"; cin>>A.IP.singkatan; cout<<endl;
    A.AP = alokasi_sll(A.IP);
    insert_last_sll(A.LP,A.AP);
    view_list_sll(A.LP);
}

void insert_relasi (setting_menu &SM, atur &A) {
    switch (SM.menu){
    case 1 :
        {
            insert_relasi1 (SM,A);
        }
        break;
    case 2 :
        {
            insert_relasi2 (SM,A);
        }
        break;
    case 3 :
        {
            insert_relasi3 (SM,A);
        }
        break;
    case 4 :
        {
            insert_relasi4 (SM,A);
        }
        break;
    case 5 :
        {
            insert_relasi5 (SM,A);
        }
        break;
    case 6 :
        {
            insert_relasi6 (SM,A);
        }
        break;
    case 7 :
        {
            insert_relasi7 (SM,A);
        }
        break;
    }
}

void insert_relasi1 (setting_menu &SM, atur &A){
    cout<<"Masukkan nama orang : "<<endl;
    cin>>SM.word;
    cout<<endl;
    SM.menu = 2;
    insert_relasi(SM,A);
}

void insert_relasi2 (setting_menu &SM, atur &A){
    list_orang OR = A.LO;
    SM.loop_cari = 0;
    while (OR.first != NULL){
       if (OR.first->info.nama == SM.word){
            SM.loop_cari++;
            SM.nampung[SM.loop_cari] = OR.first->info;
       }
       OR.first = OR.first->next;
    }
    if (SM.loop_cari != NULL){
        SM.menu = 4;
        insert_relasi(SM,A);
    }
    else {
        SM.menu = 3;
        insert_relasi(SM,A);
    }
}

void insert_relasi3 (setting_menu &SM, atur &A){
    system("CLS");
    cout<<"Nama tidak ditemukan."<<endl;
    cout<<"1. Cari data"<<endl;
    cout<<"2. Kembali ke menu insert"<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {
            SM.menu = 2;
            insert_relasi(SM,A);
        }
        break;
    case 2 :
        {
            insert_menu(SM,A);
        }
        break;
    }
}

void insert_relasi4 (setting_menu &SM, atur &A){
    system("CLS");
    cout<<"Berikut data hasil pencarian :"<<endl;
    SM.loop_cari2 = 1;
    while (SM.loop_cari2 <= SM.loop_cari){
        cout<<"ID : "<< SM.nampung[SM.loop_cari2].id<<endl;
        cout<<"Nama : "<< SM.nampung[SM.loop_cari2].nama<<endl;
        cout<<"Tanggal Lahir : "<< SM.nampung[SM.loop_cari2].tanggallahir.tanggal<<endl;
        cout<<"Tanggal Lahir : "<< SM.nampung[SM.loop_cari2].tanggallahir.bulan<<endl;
        cout<<"Tanggal Lahir : "<< SM.nampung[SM.loop_cari2].tanggallahir.tahun<<endl;
        SM.loop_cari2++;
    }
    cout<<"Masukkan ID yang telah anda cari : "<<endl;
    cin>>A.IA.id_orang;
    cout<<endl;
    SM.loop_cari2 = 1;
    while ((A.IA.id_orang != SM.nampung[SM.loop_cari2].id) && (SM.loop_cari2 <= SM.loop_cari)){
        SM.loop_cari2++;
    }
    if (A.IA.id_orang == SM.nampung[SM.loop_cari2].id){
       SM.menu = 5;
       insert_relasi(SM,A);
    }
    else{
        cout<<"ID yang anda masukkan SALAH"<<endl;
        system("PAUSE");
        SM.menu = 4;
        insert_relasi(SM,A);
    }
}
void insert_relasi5 (setting_menu &SM, atur &A){
    system("CLS");
    cout<<"Berikut data hasil orang :"<<endl;
    cout<<"ID : "<< SM.nampung[SM.loop_cari2].id<<endl;
    cout<<"Nama : "<< SM.nampung[SM.loop_cari2].nama<<endl;
    cout<<"Tanggal Lahir : "<< SM.nampung[SM.loop_cari2].tanggallahir.tanggal<<endl;
    cout<<"Tanggal Lahir : "<< SM.nampung[SM.loop_cari2].tanggallahir.bulan<<endl;
    cout<<"Tanggal Lahir : "<< SM.nampung[SM.loop_cari2].tanggallahir.tahun<<endl;

    cout<<"Pilihlah data pendidikan yang anda pilih"<<endl;
    list_pendidikan PD = A.LP;
    while (PD.first != NULL){
        cout<<"ID : "<< PD.first->info.id<<endl;
        cout<<"Singkatan : "<< PD.first->info.singkatan<<endl;
        cout<<"Kepanjangan : "<< PD.first->info.kepanjangan<<endl;
        PD.first = PD.first->next;
    }
    cout<<"Masukkan ID pendidikan yang telah disediakan : "<<endl;
    cin>>A.IA.id_pendidikan;
    cout<<endl;
    SM.menu = 6;
    insert_relasi(SM,A);
}

void insert_relasi6 (setting_menu &SM, atur &A){
    list_orang OR = A.LO;
    while (OR.first->info.id != A.IA.id_orang){
        OR.first = OR.first->next;
    }
    cout<<"ID : "<< OR.first->info.id<<endl;
    cout<<"Nama : "<< OR.first->info.nama<<endl;
    cout<<"Tanggal Lahir : "<< OR.first->info.tanggallahir.tanggal<<endl;
    cout<<"Tanggal Lahir : "<< OR.first->info.tanggallahir.bulan<<endl;
    cout<<"Tanggal Lahir : "<< OR.first->info.tanggallahir.tahun<<endl;

    list_pendidikan PD = A.LP;
    while (OR.first->info.id != A.IA.id_orang){
        OR.first = OR.first->next;
    }
    cout<<"ID : "<< PD.first->info.id<<endl;
    cout<<"Singkatan : "<< PD.first->info.singkatan<<endl;
    cout<<"Kepanjangan : "<< PD.first->info.kepanjangan<<endl;
    cout<<endl;
    cout<<"Apakah anda ingin menyimpan data tersebut ? "<<endl;
    cout<<"1. Ya                2. Tidak "<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {
            SM.menu = 7;
            insert_relasi(SM,A);
        }
        break;
    case 2 :
        {
            insert_menu(SM,A);
        }
        break;
    }
}

void insert_relasi7 (setting_menu &SM, atur &A){
    A.AA = alokasi_cdll(A.IA);
    insert_after_cdll(A.LA,A.AA);

}

void delete_menu(setting_menu &SM, atur &A){
    cout << "Silahkan pilih menu yang anda inginkan :" << endl;
    cout << "1. Delete Orang" << endl;
    cout << "2. Delete Data Pendidikan" << endl;
    cout << "3. Delete Relasi" << endl;
    cout << "4. Back" << endl;
    cout<<"Masukin pilihan anda :"<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {

            //delete_after_dll(A.LO, prec, A.AO);
        }
        break;
    case 2 :
        {
            //delete_after_sll(A.LP, A.AP);
        }
        break;
    case 3 :
        {
            //delete_after_cdll(list l, address &p, address prec);
        }
        break;
    case 4 :
        {
            pilihanbaru(SM,A);
        }
    }
}

/*void delete_orang (setting_menu &SM, atur &A){
    string cari;
    cout<<"SILAHKAN MASUKKAN NAMA YANG DICARI"<<endl;
    cout<<"Nama :";
    cin>>cari.nama; cout<<endl;
    list_orang baru = A.LO;
    bool searching = false;
    while (searching<>true){
        if (cari == A.LO.first->info.nama){
            delete_after_dll(A.AO,A.LO);
        }
    }
}*/

/*void delete_pendidikan (setting_menu &SM, atur &A){
    string cari2;
    cout<<"SILAHKAN MASUKKAN NAMA YANG DICARI"<<endl;
    cout<<"Nama :"; cin>>cari2.singkatan; cout<<endl;
    list_orang baru2 = A.LP;
    bool searching2 = false;
    while (searching2<>true){
        if (cari == A.LP.first->info.singkatan){
            delete_after_dll(A.AO,A.LO);
        }
    }
}*/

void update_menu(setting_menu &SM, atur &A){
    cout << "Silahkan pilih menu yang anda inginkan :" << endl;
    cout << "1. Update Orang" << endl;
    cout << "2. Update Relasi" << endl;
    cout << "3. Back" << endl;
    cout<<"Masukin pilihan anda :"<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {
            //update_dll();
        }
        break;
    case 2 :
        {
            //update_cdll();
        }
        break;
    case 3 :
        {
            pilihanbaru(SM,A);
        }
        break;
    }
}

void view_menu(setting_menu &SM, atur &A){
    cout << "Silahkan pilih menu yang anda inginkan :" << endl;
    cout << "1. View Orang" << endl;
    cout << "2. View Relasi" << endl;
    cout << "3. View Data Pendidikan" << endl;
    cout << "4. Back" << endl;
    cout<<"Masukin pilihan anda :"<<endl;
    cin>>SM.menu;
    switch (SM.menu){
    case 1 :
        {
            print_orang(SM,A);
            view_menu(SM,A);
        }
        break;
    case 2 :
        {
            print_pendidikan(SM,A);
            view_menu(SM,A);
        }
        break;
    case 3 :
        {
            print_relasi(SM,A);
            view_menu(SM,A);
        }
        break;
    case 4 :
        {
            pilihanbaru(SM,A);
        }
    }
}

void print_orang (setting_menu &SM, atur &A){
    view_list_dll(A.LO);
}

void print_pendidikan (setting_menu &SM, atur &A){
    view_list_sll(A.LP);
}

void print_relasi (setting_menu &SM, atur &A){
    view_list_cdll(A.LA);
}
