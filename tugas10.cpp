#include <iostream>
using namespace std;
class buku
{
    string judul;

public:
    buku setjudul (sring judul);
 {
    this->judul = judul;
    return *this // chain function
 }
string getJudul()
{
    return->this = judul;
}

}bukunya;

int main()
{
    //bukunya.setjudul ("matematika");
    //cout << bukunya.getjudul();
     cout << bukunya.setjudul ("matematika").getjudul(); chaing function calls;
     return 0; 
}