//Definicion de pocicion inicial,  
//libretia y funcion del servo motor.
#include <Servo.h>
int pos = 0;
Servo servo_9;
//Definicion de constantes para la asignacion de pines.
const int pinesEntrada[4] = { 10, 11, 12, 13 };

void setup()
{
  //Asignacion de pines de entrada
    for(int i = 0; i < 4; i++) {
    pinMode(pinesEntrada[i], INPUT);  
  }
  servo_9.attach(9);
}

void loop()
{
   /*Entradas binarias*/
    int x = digitalRead(pinesEntrada[0]);
  int y = digitalRead(pinesEntrada[1]);
    int z = digitalRead(pinesEntrada[2]);
    int w = digitalRead(pinesEntrada[3]);
  
    if (x == LOW && y == LOW && z == HIGH && w == HIGH){
      // barrer el servo de 0 a 720 grados 
      // en pasos de 1 grados
      for (pos = 0; pos <= 720; pos += 1) {
        // Indica al servo que vaya a la posición 'pos'.
        servo_9.write(pos);
        // Retardo de 15 milisegundos
        delay(15);
      }
      //Regresa el servo motor a la posision 0
      for (pos = 720; pos >= 0; pos -= 1) {
        servo_9.write(pos);
        delay(15);
        }
  }
    else if (x == LOW && y == LOW && z == HIGH && w == LOW){
      // barrer el servo de 0 a 180 grados 
      // en pasos de 1 grados
      for (pos = 0; pos <= 180; pos += 1) {
        // Indica al servo que vaya a la posición 'pos'.
        servo_9.write(pos);
        // Retardo de 15 milisegundos
        delay(15);
      }
        //Regresa el servo motor a la posision 0
      for (pos = 180; pos >= 0; pos -= 1) {
        servo_9.write(pos);
        delay(15);
        }
    }
  
  else if (x == LOW && y == HIGH && z == LOW && w == HIGH){
      // barrer el servo de 0 a 270 grados 
      // en pasos de 1 grados
      for (pos = 0; pos <= 270; pos += 1) {
        // Indica al servo que vaya a la posición 'pos'.
        servo_9.write(pos);
        // Retardo de 15 milisegundos
        delay(15);
      }
      //Regresa el servo motor a la posision 0
      for (pos = 270; pos >= 0; pos -= 1) {
        servo_9.write(pos);
        delay(15);
        }
     }
  
  else if (x == HIGH && y == HIGH && z == HIGH && w == HIGH){
      // barrer el servo de 0 a 45 grados 
      // en pasos de 1 grados
      for (pos = 0; pos <= 45; pos += 1) {
        // Indica al servo que vaya a la posición 'pos'.
        servo_9.write(pos);
        // Retardo de 15 milisegundos
        delay(15);
      }
      //Regresa el servo motor a la posision 0
      for (pos = 45; pos >= 0; pos -= 1) {
        servo_9.write(pos);
        delay(15);
        }
    }
}

    
