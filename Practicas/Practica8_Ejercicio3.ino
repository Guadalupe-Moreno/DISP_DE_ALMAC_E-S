//Definicion de constantes para la asignacion de pines y tiempo.
const int pinesSalida[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
const int pinesEntrada[4] = { 9, 10, 11, 12 };

//Definicion de la tabla para el despliegue en un display de 7
//segmentos con catodo comun
const byte numerosDisplay[10] = { 0b0111111,    //0
                                  0b0000110,    //1
                                  0b1011011,    //2
                                  0b1001111,    //3
                                  0b1100110,    //4
                                  0b1101101,    //5
                                  0b1111101,    //6
                                  0b0000111,    //7
                                  0b1111111,    //8
                                  0b1101111};   //9

//Variable que va a guardar el numero que se va a leer
int numero = 0;

void setup() {
   //Asignacion de pines de salida.
    for(int i = 0; i < 8; i++) {
      pinMode(pinesSalida[i], OUTPUT);  
  }
  //Asignacion de pines de entrada
    for(int i = 0; i < 4; i++) {
    pinMode(pinesEntrada[i], INPUT);  
  }
}
void loop() {//Codigo del contador del 0 al 9
  /*Entradas binarias*/
  int x = digitalRead(pinesEntrada[0]);
  int y = digitalRead(pinesEntrada[1]);
  int z = digitalRead(pinesEntrada[2]);
  int w = digitalRead(pinesEntrada[3]);
  
  if(x == HIGH && w == HIGH){
      prenderSegmentos(9);
  }
  else if(x == HIGH && z == HIGH){
      prenderSegmentos(5);
  } 
  else if(x == LOW && z == HIGH){
      prenderSegmentos(8);
  } 
  else{
      prenderSegmentos(0);
  }
}
//Funcion para desplegar el numero en el display
void prenderSegmentos(int numero) {
  byte numeroBinario = numerosDisplay[numero];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numeroBinario, i);
    digitalWrite(pinesSalida[i], bit);
  }
}
