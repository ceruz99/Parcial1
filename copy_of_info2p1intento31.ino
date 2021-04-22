
/*////////////////////////////////////////////////////////
MANUAL PARA USUARIO.


Descripcion:
El programa le permitira mostrar patrones, imagenes o letras
de manera consecutiva para mostrar frases en la pantalla de 
64 leds que se encuentra organizada como en la Figura1. A
continuación las instrucciones de uso.

Figura1.

Columnas:
 8  7  6  5  4  3  2  1
[1][1][1][1][1][1][1][1]
[2][2][2][2][2][2][2][2]
[3][3][3][3][3][3][3][3]
[4][4][4][4][4][4][4][4]
[5][5][5][5][5][5][5][5]
[6][6][6][6][6][6][6][6]
[7][7][7][7][7][7][7][7]
[8][8][8][8][8][8][8][8]
 

Al ser inicializado el programa, este le enseñara un menu en
el cual puede seleccionar entre las funciones verificacion,
imagen y publik.
Debe ingresar el numero 1 si desea acceder a la funcion 
verificacion.
Debe ingresar el numero 2 si desea acceder a la funcion imagen.
Debe ingresar el numero 3 si desea acceder a la funcion publik.

Funcion verificacion: Le permitira verificar que los 64 leds del
sistema estan en correcto funcionamiento.

Funcion imagen: Le permitira mostrar de manera fija un patron
que desee.
	Modo de uso imagen:
    1. El programa le mostrara la matriz de 64 posiciones.
    2. Empezando por la columna 1(Figura1) señalada con los
    simbolos "^^^", se le pedira que ingrese en el monitor 
    numeros entre el 0 y el 8.
    3.Los numeros del 1 al 8 representan las posiciones 
    respectivamente en la matriz de leds de 8x8 y el numero
    0 representa que no se quiere utilizar ningun led de la
    columna.
    4. Los numeros deben ser ingresados del menor al mayor,
    ejemplo: 1234, 2567, 458, etc.
    5. Luego de ingresar los numeros para la primera columna
    que se le solicita, se le pediran los numeros para la 
    siguiente columna que es la columna 2(Figura1), luego 
    para la columna 3, y así sucesivamente hasta llegar a la
    columna8.
    6.Finalizada esta etapa el patron se imprimira en la matriz
    de leds.

Funcion publik: Le permite mostrar varios patrones de forma 
consecutiva.
	Modo de uso publik:
    1. El programa le preguntara cuantos patrones desea 
    imprimir, debe ingresar el numero en el monitor.
    2. El programa le mostrara la matriz de 64 posiciones.
    3. Empezando por la columna 1(Figura1) señalada con los
    simbolos "^^^", se le pedira que ingrese en el monitor
    numeros entre el 0 y el 8.
    4.Los numeros del 1 al 8 representan las posiciones 
    respectivamente en la matriz de leds de 8x8 y el numero
    0 representa que no se quiere utilizar ningun led de la
    columna.
    5. Los numeros deben ser ingresados del menor al mayor,
    ejemplo: 1234, 2567, 458, etc.
    6. Luego de ingresar los numeros para la primera columna
    que se le solicita, se le pediran los numeros para la 
    siguiente columna que es la columna 2(Figura1), luego 
    para la columna 3, y así sucesivamente hasta llegar a la
    columna8.
    7.Una vez completadas las 8 columnas, el programa volvera
    a pedirle nuevamente otras 8 columnas para el siguiente 
    patron.
    8.Dicho lo anterior el proceso se repetira un numero de 
    veces segun el numero de patrones deseados.
    9.Finalizado lo anterior la matriz imprimira de forma
    ordenada y consecutiva los patrones que se ingresaron,
    para dejar de repetir la secuencia se debe ingresar al
    monitor el numero 0.

*////////////////////////////////////////////////////////

const int SER=2;
const int RCLK=3;
const int SCRLK=4;
const int SRCLR=12;
int datou=B11111111;
int datod=B10001000;



/*La función verificación permite al usuario verificar que 
los 64 leds estan funcionales.*/
void verificacion();
/*imagen permite imprimir en los 64 leds el patrón que
se desee.*/
void imagen();
/*Publik permite mostrar varios patrones en los leds.*/
void publik();
/* decimalColumna Toma los numeros del 1 al 8 ingresados por 
el usuario y los vuelve un solo decimal*/
int decimalColumna(long int );
/*aBinario toma un numero decimal y lo convierte a binario.*/
long int aBinario(long int n );
/*counterDigits cuenta el numero de digitos de un entero.*/
int counterDigits(long int a);
/*potencia eleva un numero "a" a una potencia "b".*/
long int potencia(int a, int b);


void setup()
{
  Serial.begin(9600);
  pinMode(SER,OUTPUT);
  pinMode(RCLK,OUTPUT);
  pinMode(SCRLK,OUTPUT);
  pinMode(SRCLR,OUTPUT);
  
  digitalWrite(SER,0);
  digitalWrite(RCLK,0);
  digitalWrite(SCRLK,0);
  digitalWrite(SRCLR,0);
  digitalWrite(SRCLR,1);
  
  int repeat=0;
}

void loop()
{
  
  Serial.println("Ingrese la opcion del proceso que desea realizar: ");
  Serial.println("1.Verificacion.");
  Serial.println("2.Imagen.");
  Serial.println("3.Publik.");
  
  while(Serial.available()== 0);
  	int option = Serial.parseInt();
  switch(option){
    case 1:{
    verificacion();
      break;
    }
    case 2:{
    imagen();
      break;
    }
    case 3:{
    publik();
    	break;
    }
  }

}

void verificacion(){
     for(int i=0;i<8;i++){
      shiftOut(SER, SCRLK, MSBFIRST, B11111111);

      digitalWrite(RCLK,0);
      digitalWrite(RCLK,1);
      digitalWrite(RCLK,0);
     }
}

void imagen(){
  	//Serial.begin(9600);
  
    int patron[8][8];
    int digits=0;
    int spacesl=21;
    int spacesr=0;
    long int binaryResult=0;
    for(int i=0;i<8;i++){

      Serial.println("[1][1][1][1][1][1][1][1]");
      Serial.println("[2][2][2][2][2][2][2][2]");
      Serial.println("[3][3][3][3][3][3][3][3]");
      Serial.println("[4][4][4][4][4][4][4][4]");
      Serial.println("[5][5][5][5][5][5][5][5]");
      Serial.println("[6][6][6][6][6][6][6][6]");
      Serial.println("[7][7][7][7][7][7][7][7]");
      Serial.println("[8][8][8][8][8][8][8][8]");

       for(int j=0;j<spacesl;j++) Serial.print(" ");
       Serial.print("^^^");
       for(int j=0;j<spacesr;j++) Serial.print(" ");
       spacesl-=3;
       spacesr+=3;
		
       Serial.println(" ");
       Serial.println("Por favor ingrese los numeros del 1 al 8 en la columna que esta senalada: ");
       while(Serial.available()== 0);
      	long int numbers = Serial.parseInt();
        if(numbers==0){
        	for(int j=0;j<8;j++){
                patron[i][j]=0;
            }
        }
        else{
          binaryResult=aBinario(decimalColumna(numbers));
          digits=counterDigits(binaryResult);
          if(digits<8){
              for(int j=0;j<8-digits;j++){
                  patron[i][j]=0;
              }
          }
          long int divider=potencia(10,digits-1);
          long int answer=binaryResult;
          for(int j=8-digits;j<8;j++){
              patron[i][j]=answer/divider;
              answer=answer%divider;
              divider=divider/10;
          }
        }
    }
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
      digitalWrite(SER,patron[i][j]);
        
      digitalWrite(SCRLK,0);
      digitalWrite(SCRLK,1);
      digitalWrite(SCRLK,0);
      }
    }
  	digitalWrite(RCLK,0);
    digitalWrite(RCLK,1);
    digitalWrite(RCLK,0);
      
}

void publik(){
  	//Serial.begin(9600);
  	Serial.println("Ingrese el numero de patrones que desea imprimir.");
  	while(Serial.available()== 0);
      	int nPatrones = Serial.parseInt();
    int patron[nPatrones][8][8];
    int digits=0;
    
    long int binaryResult=0;
  	for(int p=0;p<nPatrones;p++){
      int spacesl=21;
      int spacesr=0;
      for(int i=0;i<8;i++){
        
        Serial.println("[1][1][1][1][1][1][1][1]");
        Serial.println("[2][2][2][2][2][2][2][2]");
        Serial.println("[3][3][3][3][3][3][3][3]");
        Serial.println("[4][4][4][4][4][4][4][4]");
        Serial.println("[5][5][5][5][5][5][5][5]");
        Serial.println("[6][6][6][6][6][6][6][6]");
        Serial.println("[7][7][7][7][7][7][7][7]");
        Serial.println("[8][8][8][8][8][8][8][8]");

         for(int j=0;j<spacesl;j++) Serial.print(" ");
         Serial.print("^^^");
         for(int j=0;j<spacesr;j++) Serial.print(" ");
         spacesl-=3;
         spacesr+=3;

         Serial.println(" ");
         Serial.println("Por favor ingrese los numeros del 1 al 8 en la columna que esta senalada: ");
         while(Serial.available()== 0);
          long int numbers = Serial.parseInt();
          if(numbers==0){
              for(int j=0;j<8;j++){
                  patron[p][i][j]=0;
              }
          }
          else{
            binaryResult=aBinario(decimalColumna(numbers));
            digits=counterDigits(binaryResult);
            if(digits<8){
                for(int j=0;j<8-digits;j++){
                    patron[p][i][j]=0;
                }
            }
            long int divider=potencia(10,digits-1);
            long int answer=binaryResult;
            for(int j=8-digits;j<8;j++){
                patron[p][i][j]=answer/divider;
                answer=answer%divider;
                divider=divider/10;
            }
          }
      }
    }
  	Serial.println("Ingrese el valor 0 para dejar de reproducir el patron");
  	while(Serial.available()== 0){
      for(int p=0;p<nPatrones;p++){
        for(int i=0;i<8;i++){
          for(int j=0;j<8;j++){
          digitalWrite(SER,patron[p][i][j]);

          digitalWrite(SCRLK,0);
          digitalWrite(SCRLK,1);
          digitalWrite(SCRLK,0);
          }
        }
        digitalWrite(RCLK,0);
        digitalWrite(RCLK,1);
        digitalWrite(RCLK,0);
        
        delay(1000);
        
        digitalWrite(SER,0);
        
        digitalWrite(SCRLK,0);
        digitalWrite(SCRLK,1);
        digitalWrite(SCRLK,0);
        
        digitalWrite(RCLK,0);
        digitalWrite(RCLK,1);
        digitalWrite(RCLK,0);
      }
    }
}

int decimalColumna(long int a){
    int b=counterDigits(a);
    int *p=new int[counterDigits(a)];
    int decimal=0;
    int k=b-1;
    long int datoFinal=a;
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

long int aBinario(long int n ){
    long int dato=n, result=0;
    for(int i=0;i<8;i++){
        if((dato%2)!=0) result+=1*potencia(10,i);
        dato=dato/2;
    }
    return result;
}

int counterDigits(long int a){
    int count=1;
    while(a>9){
        a=a/10;
        count+=1;
    }
    return count;
}

long int potencia(int a, int b){
    long int resultado=1;
    for(int i=0; i<b; i++)
    {
        resultado*=a;
    }
    return resultado;
}