// JUDUL

/*
KONVERSI MATA UANG IDR, USD, JPY (Dengan ADT, Function, Procedure)
DASAR PEMROGRAMAN A11.4104
KELOMPOK 3
Anggota:
Valentio Titan Sugiyarto     A11.2024.15676
Mohammad Riziq Subhan        A11.2024.15757
Amanda Zaskia Ramadhani      A11.2024.15756
*/

#include <iostream>
#include <limits>
using namespace std;

// KAMUS
struct Uang {
    int input;      // Variabel jumlah uang yang diinput
    int asal;       // Variabel input memilih mata uang asal
    int tujuan;     // Variabel input memilih mata uang tujuan
    double hasil;   // Variabel hasil konversi
};

struct Kurs {                     // ADT Kurs Mata Uang
    struct {                      // KURS IDR
        double USD = 0.000066;    // Kurs IDR ke USD
        double JPY = 0.0073;      // Kurs IDR ke JPY
    } IDR;

    struct {                      // KURS USD
        double IDR = 15000.0;     // Kurs USD ke IDR
        double JPY = 110.0;       // Kurs USD ke JPY
    } USD;

    struct {                      // KURS JPY
        double IDR = 137.0;       // Kurs JPY ke IDR
        double USD = 0.0091;      // Kurs JPY ke USD
    } JPY;
};

struct Uang uang;                // Variabel ADT Uang
struct Kurs kurs;                // Variabel ADT Kurs

void tampilan_pembuka();         // Procedure untuk menampilkan judul program yang akan digunakan user
void informasi_kurs();           // Procedure untuk menampilkan informasi kurs mata uang yang akan digunakan
int uang_asal();                 // Function untuk memilih mata uang asal (IDR, USD, JPY)
int uang_tujuan();               // Function untuk memilih mata uang tujuan (IDR, USD, JPY)
int uang_input();                // Function untuk menyimpan nilai uang yang diinput
double konversi();               // Function untuk memproses konversi
void hasil();                    // Procedure untuk menampilkan hasil konversi
void rangkuman();                // Procedure untuk menampilkan rangkuman konversi
void konfirmasi_ulang();         // Procedure untuk konfirmasi menggunakan ulang program
void tampilan_akhir();           // Procedure untuk menyatakan program telah selesai

char ulang;                      // Variabel untuk mengulangi program

// DESKRIPSI :
int main() {
    do {
        tampilan_pembuka();
        informasi_kurs();
        uang_asal();
        uang_tujuan();
        uang_input();
        hasil();
        rangkuman();
        konfirmasi_ulang();
        tampilan_akhir();
    } while (ulang == 'Y' || ulang == 'y');
    return 0;
}

void tampilan_pembuka() {
    // Tampilan pembuka
    // Menyatakan informasi program yang akan digunakan
    cout << "===================================" << endl;
    cout << "   KONVERSI MATA UANG KELOMPOK 3   " << endl;
    cout << "===================================" << endl;
    cout << "Selamat Datang di Aplikasi" << endl;
    cout << "Konversi Mata Uang Sederhana" << endl;
    cout << "Konversi: IDR, USD, JPY" << endl;
}

void informasi_kurs() {
    // Tampilan informasi kurs yang akan digunakan
    cout << "===================================" << endl;
    cout << "INFORMASI KURS MATA UANG:" << endl;
    cout << "1. IDR ke USD: " << kurs.IDR.USD << endl;
    cout << "2. IDR ke JPY: " << kurs.IDR.JPY << endl;
    cout << "3. USD ke IDR: " << kurs.USD.IDR << endl;
    cout << "4. USD ke JPY: " << kurs.USD.JPY << endl;
    cout << "5. JPY ke IDR: " << kurs.JPY.IDR << endl;
    cout << "6. JPY ke USD: " << kurs.JPY.USD << endl;
    cout << "===================================" << endl;
}

int uang_asal() {
    // User interface untuk memilih mata uang asal
    cout << "Mata Uang Asal: " << endl;
    cout << "1. Rupiah (IDR)" << endl;
    cout << "2. Dolar AS (USD)" << endl;
    cout << "3. Yen (JPY)" << endl;
    cout << "Pilih mata uang asal (1=IDR, 2=USD, 3=YEN): ";
    cin >> uang.asal;

    // Validasi input mata uang asal
   while (cin.fail() || uang.asal < 1 || uang.asal > 3) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Input tidak valid. Masukkan angka 1-3 (1=IDR, 2=USD, 3=YEN): ";
        cin >> uang.asal;
    }

    cout << "-----------------------------------" << endl;
    return uang.asal;
}

int uang_tujuan() {
    // User interface untuk memilih mata uang tujuan
    cout << "Mata Uang Tujuan: " << endl;
    cout << "1. Rupiah (IDR)" << endl;
    cout << "2. Dolar AS (USD)" << endl;
    cout << "3. Yen (JPY)" << endl;
    cout << "Pilih mata uang tujuan (1=IDR, 2=USD, 3=YEN): ";
    cin >> uang.tujuan;

    // Validasi input mata uang tujuan
    while (cin.fail() || uang.tujuan < 1 || uang.tujuan > 3 || uang.tujuan == uang.asal) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail() || uang.tujuan < 1 || uang.tujuan > 3) {
            cout << "Input tidak valid. Masukkan angka 1-3 (1=IDR, 2=USD, 3=YEN): ";
        } else if (uang.tujuan == uang.asal) {
            cout << "Mata uang tujuan tidak boleh sama dengan mata uang asal. Pilih mata uang lain: ";
        }
        cin >> uang.tujuan;
    }

    cout << "-----------------------------------" << endl;
    return uang.tujuan;
}

int uang_input() {
    // User interface untuk menginput jumlah uang
    cout << "Masukkan Jumlah Uang: ";
    cin >> uang.input;

    // Validasi input jumlah uang
    while (cin.fail() || uang.input <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Jumlah uang tidak valid. Masukkan jumlah uang berupa angka positif: ";
        cin >> uang.input;
    }

    cout << "===================================" << endl;
    return uang.input;
}

double konversi() {
    if (uang.asal == 1 && uang.tujuan == 2) // IDR ke USD
        uang.hasil = uang.input * kurs.IDR.USD;
    else if (uang.asal == 1 && uang.tujuan == 3) // IDR ke JPY
        uang.hasil = uang.input * kurs.IDR.JPY;
    else if (uang.asal == 2 && uang.tujuan == 1) // USD ke IDR
        uang.hasil = uang.input * kurs.USD.IDR;
    else if (uang.asal == 2 && uang.tujuan == 3) // USD ke JPY
        uang.hasil = uang.input * kurs.USD.JPY;
    else if (uang.asal == 3 && uang.tujuan == 1) // JPY ke IDR
        uang.hasil = uang.input * kurs.JPY.IDR;
    else if (uang.asal == 3 && uang.tujuan == 2) // JPY ke USD
        uang.hasil = uang.input * kurs.JPY.USD;
    else // Asal dan tujuan sama
        uang.hasil = uang.input;

    return uang.hasil;
}

void hasil() {
    // Memanggil fungsi konversi untuk memastikan `uang.hasil` sudah dihitung
    konversi();

    // Output hasil konversi
    cout << "HASIL KONVERSI: ";
    if (uang.tujuan == 1)
        cout << "IDR ";
    else if (uang.tujuan == 2)
        cout << "USD ";
    else if (uang.tujuan == 3)
        cout << "JPY ";
    cout << uang.hasil;

    cout << endl << "===================================" << endl;
}

void rangkuman() {
    // Rangkuman Hasil Konversi
    cout << "KONVERSI BERHASIL!" << endl;

    // Mata uang asal hasil input user
    cout << "Mata Uang Asal: ";
    if (uang.asal == 1) cout << "IDR";
    else if (uang.asal == 2) cout << "USD";
    else if (uang.asal == 3) cout << "JPY";

    // Mata uang tujuan hasil input user
    cout << endl << "Mata Uang Tujuan: ";
    if (uang.tujuan == 1) cout << "IDR";
    else if (uang.tujuan == 2) cout << "USD";
    else if (uang.tujuan == 3) cout << "JPY";

    // Jumlah uang hasil input user
    cout << endl << "Jumlah Uang: " << uang.input;

    // Hasil konversi oleh input user
    cout << endl << "Hasil Konversi: ";
    if (uang.tujuan == 1) cout << "IDR ";
    else if (uang.tujuan == 2) cout << "USD ";
    else if (uang.tujuan == 3) cout << "JPY ";
    cout << uang.hasil;
}

void konfirmasi_ulang() {
    // Konfirmasi user untuk menggunakan program kembali
    cout << endl << "===================================" << endl;
    cout << "Konversi mata uang lainnya? (y/n): ";
    cin >> ulang;

    while (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N') {
        cout << "Input tidak valid. Masukkan 'Y' untuk ya atau 'N' untuk tidak: ";
        cin >> ulang;
    }

    cout << endl;
}

void tampilan_akhir() {
    // Tampilan akhir
    // Menyatakan bahwa program telah berhenti
    cout << "===================================" << endl;
    cout << "Terima kasih telah menggunakan program konversi mata uang!" << endl;
}
