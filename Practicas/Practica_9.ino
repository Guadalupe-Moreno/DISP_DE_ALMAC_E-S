
// Definimos los pines donde tenemos conectadas las bobinas
#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11
const int pinesEntrada[4] = { 4, 5, 6, 7 };
int retardo=5;          // Tiempo de retardo en milisegundos (Velocidad del Motor)
int dato_rx;            // valor recibido en grados
int numero_pasos = 0;   // Valor en grados donde se encuentra el motor
void setup()
{
  Serial.begin(9600);  
  // Todos los pines en modo salida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}



void loop()
{ 


   /*Entradas binarias*/
  bool x = digitalRead(pinesEntrada[0]);
  bool y = digitalRead(pinesEntrada[1]);
  bool z = digitalRead(pinesEntrada[2]);
  bool w = digitalRead(pinesEntrada[3]);
int numero = 0;

  /*Se guarda la entrada binaria en su respectivo orden xyzw*/
  numero = x << 3;
  numero |= y << 2;
  numero |= z << 1;
  numero |= w << 0;

  if (numero == 0b1100) { //720 Izquierda
    dato_rx=-720;
  
        Serial.print(dato_rx);         // Envia valor en Grados 
        Serial.println(" Grados");
        delay(retardo);
        dato_rx = (dato_rx / 10); // Ajuste de 512 vueltas a los 360 grados
   while (dato_rx>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();
       numero_pasos = numero_pasos + 1;
   }
   while (dato_rx<numero_pasos){   // Giro hacia la derecha en grados
        paso_der();
        numero_pasos = numero_pasos -1;
   }

  apagado();         // Apagado del Motor para que no se caliente
} 

/////////////////////////////////////////////////////////////////////////////////////
   else if (numero == 0b0010) { // 180 derecha
   
      dato_rx=180;
  
        Serial.print(dato_rx);         // Envia valor en Grados 
        Serial.println(" Grados");
        delay(retardo);
        dato_rx = (dato_rx /10); // Ajuste de 512 vueltas a los 360 grados
   while (dato_rx>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();
       numero_pasos = numero_pasos + 1;
   }
   while (dato_rx<numero_pasos){   // Giro hacia la derecha en grados
        paso_der();
        numero_pasos = numero_pasos -1;
   }
 
  apagado();         // Apagado del Motor para que no se caliente
  } 
  /////////////////////////////////////////////////////////////////////////////////////
 
  else if (numero == 0b0101) { //270 izquierda
    
      dato_rx=-270;
  
        Serial.print(dato_rx);         // Envia valor en Grados 
        Serial.println(" Grados");
        delay(retardo);
        dato_rx = (dato_rx /10); // Ajuste de 512 vueltas a los 360 grados
   while (dato_rx>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();
       numero_pasos = numero_pasos + 1;
   }
   while (dato_rx<numero_pasos){   // Giro hacia la derecha en grados
        paso_der();
        numero_pasos = numero_pasos -1;
   }
  
  apagado();         // Apagado del Motor para que no se caliente
    
  }
  ///////////////////////////////////////////////////////////////////////////////////////
  else if (numero == 0b1111) { //45 derecha

     dato_rx=45;
  
        Serial.print(dato_rx);         // Envia valor en Grados 
        Serial.println(" Grados");
        delay(retardo);
        dato_rx = (dato_rx * 1.4444); // Ajuste de 512 vueltas a los 360 grados
   while (dato_rx>numero_pasos){   // Girohacia la izquierda en grados
       paso_izq();
       numero_pasos = numero_pasos + 1;
   }
   while (dato_rx<numero_pasos){   // Giro hacia la derecha en grados
        paso_der();
        numero_pasos = numero_pasos -1;
   }

  apagado();         // Apagado del Motor para que no se caliente
  }
}
/////////////////////////////////////////////////////////////////////////////////

void paso_der(){         // Pasos a la derecha
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
   delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
   delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
  delay(retardo);  
}

void paso_izq() {        // Pasos a la izquierda
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
  delay(retardo); 
digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, HIGH);  
 digitalWrite(8, LOW);  
  delay(retardo); 
 digitalWrite(11, HIGH); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH);  
  delay(retardo); 
 digitalWrite(11, LOW); 
 digitalWrite(10, HIGH);  
 digitalWrite(9, LOW);  
 digitalWrite(8, HIGH); 
  delay(retardo); 
}
        
void apagado() {         // Apagado del Motor
 digitalWrite(11, LOW); 
 digitalWrite(10, LOW);  
 digitalWrite(9, LOW);  
 digitalWrite(8, LOW);  
 }

    
