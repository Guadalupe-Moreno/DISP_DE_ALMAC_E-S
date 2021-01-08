//Definicion de constantes para la asignacion de pines y tiempo.
const int pinesSalida[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
const int tiempoRetardo = 1000;
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

void setup() {
   //Asignacion de pines de salida.
    for(int i = 0; i < 8; i++) {
      pinMode(pinesSalida[i], OUTPUT);  
  }
}
void loop() {//Codigo del contador del 0 al 9
  for(int i = 0; i < 10; i++) {
      prenderSegmentos(i);
      delay(tiempoRetardo);
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
