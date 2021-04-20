#include <iostream>

using namespace std;

void verificacion();
void imagen();
int potencia(int , int );//Eleva un numero "a" a una potencia "b".
int counterDigits(int ); //Cuenta el numero de digitos de un entero.
int decimalColumna(int );/*Toma los numeros del 1 al 8 ingresados por el usuario y
                         los vuelve un solo decimal*/
int aBinario(int );//Toma un numero decimal y lo convierte a binario.


int main()
{
    imagen();

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

int potencia(int a, int b){
    int resultado=1;
    for(int i=0; i<b; i++)
    {
        resultado*=a;
    }
    return resultado;
}

int counterDigits(int a){
    int count=1;
    while(a>9){
        a=a/10;
        count+=1;
    }
    return count;
}

int decimalColumna(int a){
    int b=counterDigits(a);
    int *p=new int[counterDigits(a)];
    int decimal=0;
    int k=b-1;
    int datoFinal=a;
    for(int i=0;i<b-1;i++){
        *(p+i)=datoFinal/potencia(10,k);
        datoFinal=datoFinal%(potencia(10,k));
        k-=1;
    }
    *(p+(b-1))=datoFinal;
    for(int j=0;j<counterDigits(a);j++){
        decimal=decimal+potencia(2,(*(p+j))-1);
    }
    delete[] p;
    return decimal;
}

int aBinario(int n ){
    int dato=n, result=0;
    for(int i=0;i<8;i++){
        if((dato%2)!=0) result+=1*potencia(10,i);
        dato=dato/2;
    }
    return result;
}

void imagen(){
    int patron[8][8];
    int digits=0;
    int spacesl=21;
    int spacesr=0;
    int numbers=0;
    int binaryResult=0;
    for(int i=0;i<8;i++){

        cout<<"[1][1][1][1][1][1][1][1]"<<endl;
        cout<<"[2][2][2][2][2][2][2][2]"<<endl;
        cout<<"[3][3][3][3][3][3][3][3]"<<endl;
        cout<<"[4][4][4][4][4][4][4][4]"<<endl;
        cout<<"[5][5][5][5][5][5][5][5]"<<endl;
        cout<<"[6][6][6][6][6][6][6][6]"<<endl;
        cout<<"[7][7][7][7][7][7][7][7]"<<endl;
        cout<<"[8][8][8][8][8][8][8][8]"<<endl;
       for(int j=0;j<spacesl;j++) cout<<" ";
       cout<<"^^^";
       for(int j=0;j<spacesr;j++) cout<<" ";
       spacesl-=3;
       spacesr+=3;

       cout<<endl<<"Por favor ingrese los numeros del 1 al 8 en la columna que esta senalada: "<<endl;
       cin>>numbers;

        binaryResult=aBinario(decimalColumna(numbers));
        digits=counterDigits(binaryResult);
        if(digits<8){
            for(int j=0;j<8-digits;j++){
                patron[i][j]=0;
            }
        }
        int divider=potencia(10,digits-1);
        int answer=binaryResult;
        for(int j=8-digits;j<8;j++){
            patron[i][j]=answer/divider;
            answer=answer%divider;
            divider=divider/10;
        }
    }
    cout<<"terminado"<<endl;
}
