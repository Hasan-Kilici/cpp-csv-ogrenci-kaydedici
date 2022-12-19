#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

string ogrencidizisi[20] = {};

void ogrenciBul(int id){
  cout << ogrencidizisi[id]+"\n";
}

void ogrenciEkle(int id, string isim, string soyisim, string yas, string sinif) {
  ofstream file("ogrenciler.csv", ios::app);

  int data1 = id;
  string data2 = isim;
  string data3 = soyisim;
  string data4 = yas;
  string data5 = sinif;

  file << "\n" << data1 << "," << data2 << "," << data3 << "," << data4 << "," << data5;

  file.close();
  return 0;
}

void ogrenciListele() {
  ifstream file("ogrenciler.csv");
  string line;
  int i = 0;
  while (getline(file, line)) {
    i++;
    cout << line << endl;
    ogrencidizisi[i] = line;
  }
  file.close();
  return file;
}

int main() {
  int command;

  while (true) {
    cout << "Okul Paneline Hoş geldiniz\n";
    cout << "Lütfen İşlem Seçiniz:\n";
    cout << "1 : Öğrencileri Listele\n";
    cout << "2 : Öğrenci Bul\n";
    cout << "3 : Öğrenci Ekle\n";
    cin >> command;

    switch (command) {
    case 1:
      ogrenciListele();
      break;
    case 2:
      int ogrenciid;
      cout << "Öğrenci Kimliği giriniz";
      cin >> ogrenciid;
      ogrenciBul(ogrenciid);
      break;
    case 3:
      int id;
      string isim, soyisim, yas, sinif;
      cout << "Kimlik giriniz";
      cin >> id;
      cout << "İsim giriniz";
      cin >> isim;
      cout << "Soyisim giriniz";
      cin >> soyisim;
      cout << "Yaş giriniz";
      cin >> yas;
      cout << "Sınıf giriniz";
      cin >> sinif; 
      ogrenciEkle(id, isim, soyisim, yas, sinif);
      break;
    }
  }
}
