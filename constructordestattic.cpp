#include <iostream>
using namespace std;

class mahasiswa{
    private:
        static int jumlahMhs;
    public:
        string status;
        string nama;
        int nim;
        mahasiswa(string pNama, int pNim){
            status = "mahasiswa baru";
            nama = pNama;
            nim = pNim;
            cout << "mahasiswa dibuat " << nama << endl;
            cout << "Status = " << status << endl;
            ++jumlahMhs;
        };
        ~mahasiswa(){
            cout << "mahasiswa dengan nama " << nama << " di hancurkan " << endl;
            -- jumlahMhs;
        };
        static int gettotalmhs(){
            return jumlahMhs;
        };
};   

int mahasiswa::jumlahMhs = 0;

int main(){
    mahasiswa mhs1("jundi", 28);
    mahasiswa mhs2("sugeng", 23);
    mhs2.status = " Mahasiswa uzur";
    cout << mhs2.status << endl;
    mahasiswa mhs3("denis", 89);

    {
        mahasiswa mhs4("praz", 30);
        cout << "jumlah mahasiswa dalam bracket = " << mahasiswa::gettotalmhs() << endl;
    }
    cout << "jumlah mahasiswa = " << mahasiswa::gettotalmhs() << endl;
    return 0;

}