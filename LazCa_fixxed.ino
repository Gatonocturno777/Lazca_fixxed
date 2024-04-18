int ADD_IN1 = 18;                        //Input 1 del motor derecho (A1) delantero.                                  
int ADD_IN2 = 19;                        //Input 2 del motor derecho (A1) delantero.
int ADD_EnA = 3;                        //EnA para el motor derecho (A1) delantero.

int ADI_IN3 = 20;                        //Input 3 del motor izquierdo (B1) delantero.                                  
int ADI_IN4 = 21;                        //Input 4 del motor izquierdo (B1) delantero.
int ADI_EnB = 4;                        //EnB para el motor izquierdo (B1) delantero.

int ATD_IN1 = 14;                        //Input 1 del motor derecho (A2) trasero.                                  
int ATD_IN2 = 15;                        //Input 2 del motor derecho (A2) trasero.
int ATD_EnA = 5;                        //EnA para el motor derecho (A2) trasero.

int ATI_IN3 = 16;                        //Input 1 del motor izquierdo (B2) trasero.                                  
int ATI_IN4 = 17;                        //Input 2 del motor izquierdo (B2) trasero.
int ATI_EnB = 6;                        //EnB para el motor izquierdo (B2) trasero. 

int DE_Trigger = 8;                     //Trigger (emisor) del ultrasonico derecho.
int DE_Echo = 7;                        //Echo (receptor) del ultrasonico derecho.
int AT_Trigger = 10;                    //Trigger (emisor) del ultrasonico izquierdo frontal.
int AT_Echo = 9;                       //Echo (receptor) del ultrasonico izquierdo frontal.

int FotoI = A0;                       //Entrada analógica del fotoresistor izquierdo.
int FotoIC = A1;
int FotoDC = A2;
int FotoD = A3;
     
void setup(){

  pinMode(FotoI, INPUT);
  pinMode(FotoIC, INPUT);
  pinMode(FotoDC, INPUT);
  pinMode(FotoD, INPUT);

  pinMode(DE_Echo, INPUT);
  pinMode(AT_Echo, INPUT);

  // puente H 1
  pinMode(ADD_IN1, OUTPUT);              
  pinMode(ADD_IN2, OUTPUT);
  pinMode(ADD_EnA, OUTPUT);                                                                                
  pinMode(ADI_IN3, OUTPUT);          
  pinMode(ADI_IN4, OUTPUT);  
  pinMode(ADI_EnB, OUTPUT); 
  // puente H 2
  pinMode(ATD_IN1, OUTPUT);           
  pinMode(ATD_IN2, OUTPUT); 
  pinMode(ATD_EnA, OUTPUT);   
  pinMode(ATI_IN3, OUTPUT);              
  pinMode(ATI_IN4, OUTPUT);
  pinMode(ATI_EnB, OUTPUT);
  
  pinMode(DE_Trigger, OUTPUT);
  pinMode(AT_Trigger, OUTPUT);

  digitalWrite (DE_Trigger, LOW);
  digitalWrite (AT_Trigger, LOW);
  Serial.begin(9600);


}

void loop(){
  int lightVal1 = analogRead(FotoI);
  int lightVal2 = analogRead(FotoIC);
  int lightVal3 = analogRead(FotoDC);
  int lightVal4 = analogRead(FotoD);

  int negroI = (lightVal1 >= 800 && lightVal1 <= 1000) ? 1 : 0;// foto IC
  int negroIC = (lightVal2 >= 800 && lightVal2 <= 1000) ? 1 : 0; // foto DC
  int negroDC = (lightVal3 >= 800 && lightVal3 <= 1000) ? 1 : 0; // foto I
  int negroD = (lightVal4 >= 800 && lightVal4 <= 1000) ? 1 : 0; // foto D

  int verdeI = (lightVal1 >= 630 && lightVal1 <= 670) ? 1 : 0;
  int verdeIC = (lightVal2 >= 630 && lightVal2 <= 670) ? 1 : 0;
  int verdeDC = (lightVal3 >= 420 && lightVal3 <= 460) ? 1: 0;
  int verdeD = (lightVal4 >= 420 && lightVal4 <= 460) ? 1: 0;

  int rojoI = (lightVal1 >= 340 && lightVal1 <= 360) ? 1: 0;
  int rojoIC = (lightVal2 >= 340 && lightVal2 <= 360) ? 1: 0;
  int rojoDC = (lightVal3 >= 340 && lightVal3 <= 360) ? 1: 0;
  int rojoD = (lightVal4 >= 340 && lightVal4 <= 360) ? 1: 0;

  int plataI = (lightVal1 >= 420 && lightVal1 <= 460) ? 1: 0;
  int plataIC = (lightVal2 >= 420 && lightVal2 <= 460) ? 1: 0;
  int plataDC = (lightVal3 >= 420 && lightVal3 <= 460) ? 1: 0;
  int plataD = (lightVal4 >= 420 && lightVal4 <= 460) ? 1: 0;

  int t1 = pulseIn (DE_Echo, HIGH);
  int t2 = pulseIn (AT_Echo, HIGH);

  int d1 = t1/59;
  int d2 = t2/59;
  int d3 = t2/59;

  int paredDE = (d1 < 7) ? 1: 0;
  int paredAT = (d2 < 7) ? 1: 0;
  int pared = d3;

  Serial.println(lightVal1);

  digitalWrite (DE_Trigger, HIGH);
  delayMicroseconds (10);
  digitalWrite (DE_Trigger, LOW); 

  digitalWrite (AT_Trigger, HIGH);
  delayMicroseconds (10);
  digitalWrite (AT_Trigger, LOW); 



  while (negroIC == 1 && negroDC == 1) { 

    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 40);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 40);
    delay (10);
  }
  //----------------------------------------------------------------------------
  
  if (plataIC == 1 && plataDC == 1 && plataI == 1 && plataD == 1){
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);

    digitalWrite (ATD_IN1, LOW);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, LOW); 
    digitalWrite (ADI_IN4, HIGH); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);

    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  }

  if (paredAT == 1) {
    while (paredAT == 1 && paredDE == 0){
      digitalWrite (ATD_IN1, HIGH);
      digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
      analogWrite (ATD_EnA, 30);
      digitalWrite (ATI_IN3, LOW);
      digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
      analogWrite (ATI_EnB, 30);

      digitalWrite (ADD_IN1, LOW);
      digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
      analogWrite (ADD_EnA, 30);
      digitalWrite (ADI_IN3, HIGH);
      digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
      analogWrite (ADI_EnB, 30);
      delay (10);
    }
    if (pared < paredAT) {
      digitalWrite (ATD_IN1, LOW);
      digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
      analogWrite (ATD_EnA, 30);
      digitalWrite (ATI_IN3, LOW);
      digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
      analogWrite (ATI_EnB, 30);

      digitalWrite (ADD_IN1, LOW);
      digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
      analogWrite (ADD_EnA, 30);
      digitalWrite (ADI_IN3, LOW);
      digitalWrite (ADI_IN4, HIGH); // DELANTERO DERECHA
      analogWrite (ADI_EnB, 30);
      delay (10);
    } 
    if (pared > paredAT) {
      digitalWrite (ATD_IN1, LOW);
      digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
      analogWrite (ATD_EnA, 30);
      digitalWrite (ATI_IN3, LOW);
      digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
      analogWrite (ATI_EnB, 30);

      digitalWrite (ADD_IN1, HIGH);
      digitalWrite (ADD_IN2, LOW); // DELANTERO IZQUIERDA
      analogWrite (ADD_EnA, 30);
      digitalWrite (ADI_IN3, HIGH);
      digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
      analogWrite (ADI_EnB, 30);
      delay (10);
    }
    if (paredAT == 1 && paredDE == 1) {
      digitalWrite (ATD_IN1, LOW);
      digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
      analogWrite (ATD_EnA, 30);
      digitalWrite (ATI_IN3, LOW);
      digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
      analogWrite (ATI_EnB, 30);

      digitalWrite (ADD_IN1, HIGH);
      digitalWrite (ADD_IN2, LOW); // DELANTERO IZQUIERDA
      analogWrite (ADD_EnA, 30);
      digitalWrite (ADI_IN3, HIGH);
      digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
      analogWrite (ADI_EnB, 30);
      delay (10);
    }
    if (paredAT == 0) {
      digitalWrite (ATD_IN1, LOW);
      digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
      analogWrite (ATD_EnA, 30);
      digitalWrite (ATI_IN3, LOW);
      digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
      analogWrite (ATI_EnB, 30);

      digitalWrite (ADD_IN1, LOW);
      digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
      analogWrite (ADD_EnA, 30);
      digitalWrite (ADI_IN3, LOW);
      digitalWrite (ADI_IN4, HIGH); // DELANTERO DERECHA
      analogWrite (ADI_EnB, 30);
      delay (10);
    }
  }


  if (paredDE == 1) {
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, LOW); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);

  do{
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  } while (paredAT == 1);

    digitalWrite (ATD_IN1, LOW);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, LOW);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);

  do {
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  } while (paredAT == 0);
  do{
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  } while (paredAT == 1);

    digitalWrite (ATD_IN1, LOW);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, LOW);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);

  do{
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  } while (negroIC == 0 && negroDC == 0); // aqui termina la programación de los ultrasonicos
  }


  if (negroIC == 1 && negroDC == 0){
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, LOW); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  }
  if (negroIC == 0 && negroDC == 1){
    digitalWrite (ATD_IN1, LOW);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, LOW);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  } 
  
  if (negroI == 1 && negroIC == 1 && negroDC == 1 && negroD == 1){ do{
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  }while (negroIC == 0 && negroDC == 0);}// aqui termina la configuracion de el color negro

  if (verdeI == 1){do {
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, LOW); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, LOW); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);   
  } while (negroIC == 0);}

  if (verdeD == 1){do {
    digitalWrite (ATD_IN1, LOW);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, LOW);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  } while (negroDC == 0);} // aquí termina la configuración del color verde

  if (rojoI == 1 && rojoIC == 1 && rojoDC == 1 && rojoD == 1){
    digitalWrite (ATD_IN1, HIGH);
    digitalWrite (ATD_IN2, LOW); // TRASERO DERECHA
    analogWrite (ATD_EnA, 30);
    digitalWrite (ATI_IN3, LOW);
    digitalWrite (ATI_IN4, HIGH); // TRASERO IZQUIERDA
    analogWrite (ATI_EnB, 30);

    digitalWrite (ADD_IN1, LOW);
    digitalWrite (ADD_IN2, HIGH); // DELANTERO IZQUIERDA
    analogWrite (ADD_EnA, 30);
    digitalWrite (ADI_IN3, HIGH);
    digitalWrite (ADI_IN4, LOW); // DELANTERO DERECHA
    analogWrite (ADI_EnB, 30);
    delay (10);
  }
}