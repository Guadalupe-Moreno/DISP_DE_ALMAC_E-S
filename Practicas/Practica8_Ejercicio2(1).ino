
const int pinesSalida[7] = { 2, 3, 4, 5, 6, 7, 8 };

const byte numerosDisplay[10] = {0b0111111,   //0
                          0b0000110,          //1
                          0b1011011,          //2
                          0b1001111,          //3
                          0b1100110,          //4
                          0b1101101,          //5
                          0b1111101,          //6
                          0b0000111,          //7
                          0b1111111,          //8
                          0b1101111};         //9

void setup() {
    for(int i = 0; i < 7; i++) {
    pinMode(pinesSalida[i], OUTPUT);  
  }
}

void loop() {
    for(int i = 0; i < 10; i++) {
      prenderSegmentos(i);
      delay(1000);
  }
}

void prenderSegmentos(int numero) {
  byte numeroBinario = numerosDisplay[numero];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numeroBinario, i);
    digitalWrite(pinesSalida[i], bit);
  }
}
