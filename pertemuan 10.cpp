#include <iostream>
#include <string>
using namespace std;

class Mahasiswa;

class Dosen {
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string nama, string NIDN, string pangkat, float gaji)
        : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    void beriNilai(Mahasiswa* m, float nilai);

    friend class Staff; // Staff dapat mengubah pangkat

    friend float LihatGajiDosen(Dosen* d); // friend function untuk Universitas
};

class Mahasiswa {
    string nama;
    string NIM;
    float nilai;

public:
    Mahasiswa(string nama, string NIM)
        : nama(nama), NIM(NIM), nilai(0.0f) {}

    void tampilkan() {
        cout << "Nama Mahasiswa: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }

    friend class Dosen; // hanya dosen bisa mengakses nilai
};

void Dosen::beriNilai(Mahasiswa* m, float nilai) {
    m->nilai = nilai;
}

float LihatGajiDosen(Dosen* d) {
    return d->gaji;
}

class Staff {
    string nama;
    string ID;
    float gaji;

public:
    Staff(string nama, string ID, float gaji)
        : nama(nama), ID(ID), gaji(gaji) {}

    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    friend float LihatGajiStaff(Staff* s); // untuk Universitas
};

float LihatGajiStaff(Staff* s) {
    return s->gaji;
}

class Universitas {
public:
    void cekGajiDosen(Dosen* d) {
        cout << "Gaji Dosen: " << LihatGajiDosen(d) << endl;
    }

    void cekGajiStaff(Staff* s) {
        cout << "Gaji Staff: " << LihatGajiStaff(s) << endl;
    }
};

// Chain function class Buku
class Buku {
    string judul;

public:
    Buku& setJudul(string judul) {
        this->judul = judul;
        return *this;
    }

    string getJudul() {
        return judul;
    }
};

int main() {
    Buku bukunya;
    cout << "Judul Buku: " << bukunya.setJudul("Matematika").getJudul() << endl;

    Mahasiswa mhs("Dzaky", "123456");
    Dosen dsn("Pak Budi", "987654", "Lektor", 15000000);
    Staff stf("Bu Rina", "S001", 10000000);
    Universitas univ;

    dsn.beriNilai(&mhs, 85.5);
    mhs.tampilkan();

    stf.ubahPangkat(&dsn, "Guru Besar");
    univ.cekGajiDosen(&dsn);
    univ.cekGajiStaff(&stf);

    return 0;
}