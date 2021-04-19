#include <iostream>

using namespace std;

void verificacion();
void menu();

int main()
{
    menu();
    return 0;
}

void verificacion(){
    for(int i=0;i<8;i++){
       cout<<"Acá se prenden los leds ingresando un binario 11111111"<<endl;
     }

     for(int i=0;i<8;i++){
       cout<<"Acá se apagan los leds para usarlos nuevamente con otra función"<<endl;
     }
}

void menu(){
    int spacesl=21;
    int spacesr=0;
    int ans=0;
    for(int i=0;i<8;i++){
        cout<<"[8][8][8][8][8][8][8][8]"<<endl;
        cout<<"[7][7][7][7][7][7][7][7]"<<endl;
        cout<<"[6][6][6][6][6][6][6][6]"<<endl;
        cout<<"[5][5][5][5][5][5][5][5]"<<endl;
        cout<<"[4][4][4][4][4][4][4][4]"<<endl;
        cout<<"[3][3][3][3][3][3][3][3]"<<endl;
        cout<<"[2][2][2][2][2][2][2][2]"<<endl;
        cout<<"[1][1][1][1][1][1][1][1]"<<endl;
       for(int j=0;j<spacesl;j++) cout<<" ";
       cout<<"^^^";
       for(int j=0;j<spacesr;j++) cout<<" ";
       spacesl-=3;
       spacesr+=3;
       cout<<endl<<"ingrese"<<endl;
       cin>>ans;
    }

}
