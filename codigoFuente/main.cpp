#include <iostream>

using namespace std;

void verificacion();

int main()
{
     verificacion();
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
