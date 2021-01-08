//Definicion de constantes para la asignacion de pines y tiempo.
const int pinesSalida[8] = { 2, 3, 4, 5, 6, 7, 8, 9 };
const int tiempoRetardo = 600;

void setup() {
   //Asignacion de pines de salida.
    for(int i = 0; i < 8; i++) {
      pinMode(pinesSalida[i], OUTPUT);  
  }
}

void loop() {
  //Codigo del contador binario de 8 bits.
  
  for (int i = 0; i < 256; i++)
  {
     for (int j = 0; j < 8; j++)
     {
       if ( ( (i >> j) & 1 )  == 1 )
           digitalWrite(pinesSalida[j], HIGH);
       else digitalWrite(pinesSalida[j], LOW);
     }
     delay(tiempoRetardo);
  }
}
