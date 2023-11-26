#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

float koordinat[2] = {0,0};
vector<vector<int>> hist;
int n=0;


void lokasi(){ //Fungsi untuk menampilkan lokasi terkini drone
    cout<<"(";
    printf("%.2f", koordinat[0]);
    cout<<",";
    printf("%.2f", koordinat[1]);
    cout<<")"<<endl;
}
void gerak(float x, float y){ //Fungsi untuk menggerakan drone dengan input x dan y
    koordinat[0] += x;
    koordinat[1] += y;
    n +=1;
    vector <int> temp;
    for (int i = 0; i<2;i++){
        temp.push_back(koordinat[i]);
    }
    hist.push_back(temp);
}

void gerak2(float v, float t, float theta){ //Fungsi untuk menggerakan drone dengan input v,t, dan sudut
    float s = v*t;
    float x = s*cos((theta*3.14)/180);
    float y = s*sin((theta*3.14)/180);
    koordinat[0] += x;
    koordinat[1] += y;
    n += 1;
    vector <int> temp;
    for (int i = 0; i<2;i++){
        temp.push_back(koordinat[i]);
    }
    hist.push_back(temp);
}
void undo(){    //Fungsi untuk mengembalikan posisi drone sebelum digerakkan ke posisi sebelum nya
    if (n<0){   //Misal jika menggerakkan drone dari A -> B, jika menggunakan undo, drone akan kembali ke posisi awal
        cout<<"Tidak Dapat Di Undo"<<endl;
    }
    else {
        n -= 1;
        koordinat[0] = hist[n][0];
        koordinat[1] = hist[n][1];
    }
}
void redo(){    //Fungsi yang secara garis besar mengembalikan progress perjalanan drone yang telah di undo
    if (n+1<hist.size()){   //Misal jika menggerakkan drone dari A -> B, jika menggunakan undo, drone akan kembali ke posisi A
        n += 1;             //Tetapi jika menggunakan redo, drone akan kembali ke posisi sebelum di undo, yaitu di B
        koordinat[0] = hist[n][0];
        koordinat[1] = hist[n][1];    
    }
    else {
        cout<<"Tidak dapat di redo"<<endl;
    }
}

int main(){
    int a;
    vector <int> temp;
        for (int i = 0; i<2;i++){
            temp.push_back(koordinat[i]);
        }
        hist.push_back(temp);
    printf("Lokasi =>");
    lokasi();
    while (true){
        cout<<"1-Gerak(x,y) || 2-Gerak2(v,t,theta) || 3-undo || 4-redo || 5-Ingfo Lokasi"<<endl; //Pilihan fungsi yang dapat dipilih user
        cin>>a;
        if (a == 1){
            float x = 0;
            float y = 0;
            cout<<"Masukkan x y (dipisah spasi) = "; //User memasukkan input x dan y
            cin>>x;
            cin>>y;
            gerak(x,y);
            cout<<"Lokasi =>"; //Program secara otomatis mencetak lokasi akhir
            lokasi();        
        }
        else if (a==2){
            float v = 0;
            float t = 0;
            float theta = 0; 
            cout<<"Masukkan v t theta (dipisah spasi) = ";
            cin>>v;
            cin>>t;
            cin>>theta;
            gerak2(v,t,theta);
            cout<<"Lokasi =>"; //Program secara otomatis mencetak lokasi akhir
            lokasi();
        }
        else if (a==3){
            undo();
            cout<<"Lokasi =>";//Program secara otomatis mencetak lokasi akhir
            lokasi();
        }
        else if (a==4){
            redo();
            cout<<"Lokasi =>"; //Program secara otomatis mencetak lokasi akhir
            lokasi();
        }
    }
}
