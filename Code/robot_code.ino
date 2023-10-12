#include <Servo.h>
#include <SoftwareSerial.h>

Servo A;
Servo B;
Servo C;

Servo D;
Servo E;
Servo F;

Servo G;
Servo H;
Servo I;

Servo L;
Servo M;
Servo N;

Servo O;
Servo P;
Servo Q;

Servo R;
Servo S;
Servo T;

int A_Start = 90;
int B_Start = 80;
int C_Start = 100;

int D_Start = 90;
int E_Start = 100;
int F_Start = 80;

int G_Start = 90;
int H_Start = 100;
int I_Start = 80;

int L_Start = 90;
int M_Start = 80;
int N_Start = 100;

int O_Start = 90;
int P_Start = 80;
int Q_Start = 100;

int R_Start = 90;
int S_Start = 100;
int T_Start = 80;

int Up = 100;
int Down = 80;
int Mid = 90;
int Down_2 = 100;
int Up_2 = 80;
bool firstStep = true;
bool lastStep = false;
char data;
SoftwareSerial bluetooth(50, 51);
// Half step to get in the first position

void halfStep(){
  for(int i = 0; i < 80; i++){
    B.write(Down + i);
    C.write(Down_2 + i);
    A.write(Mid + 0.25 * i);
    H.write(Up - i);
    I.write(Up_2 - i);
    G.write(Mid + 0.25 * i);
    P.write(Down + i);
    Q.write(Down_2 + i);    
    O.write(Mid - 0.25 * i);
    delay(10);
  }
  for(int i = 0; i < 80; i++){
    B.write(Down + 80 - i);
    C.write(Down_2 + 80 - i);
    A.write(Mid + 20 + 0.25 * i);
    H.write(Up - 80 + i);
    I.write(Up_2 - 80 + i);
    G.write(Mid + 20 + 0.25 * i);
    P.write(Down + 80 - i);
    Q.write(Down_2 + 80 - i);
    O.write(Mid - 20 - 0.25 * i);
    delay(10);
  }
}

void halfStep2(){
  for(int i = 0; i < 80; i ++){
    B.write(Down + i);
    C.write(Down_2 + i);
    A.write(Mid - 40 + 0.25 * i);
    H.write(Up - i);
    I.write(Up_2 - i);
    G.write(Mid - 40 + 0.25 * i);
    P.write(Down + i);
    Q.write(Down_2 + i);    
    O.write(Mid + 40 - 0.25 * i);
    delay(10);
  }
  for(int i = 0; i < 80; i++){
    B.write(Down + 80 - i);
    C.write(Down_2 + 80 - i);
    A.write(Mid - 20 + 0.25 * i);
    H.write(Up - 80 + i);
    I.write(Up_2 - 80 + i);
    G.write(Mid - 20 + 0.25 * i);
    P.write(Down + 80 - i);
    Q.write(Down_2 + 80 - i);
    O.write(Mid + 20 - 0.25 * i);
    delay(10);
  }
}

// Move legs 2, 4, 6
void moveLegs1(){
  for(int i = 0; i < 80; i++){
    E.write(Up - i);
    F.write(Up_2 - i);
    D.write(Mid - 40 + 0.5 * i);
    M.write(Down + i);
    N.write(Down_2 + i);
    L.write(Mid + 40 - 0.5 * i);
    S.write(Up - i);
    T.write(Up_2 - i);
    R.write(Mid + 40 - 0.5 * i);
    delay(10);
  }
  for(int i = 0; i < 80; i++){
    E.write(Up - 80 + i);
    F.write(Up_2 - 80 + i);
    D.write(Mid + 0.5 * i);
    M.write(Down + 80 - i);
    N.write(Down_2 + 80 - i);
    L.write(Mid - 0.5 * i);
    S.write(Up - 80 + i);
    T.write(Up_2 - 80 + i);
    R.write(Mid  - 0.5 * i);
    delay(10);
  }
}

// Move legs 1, 3, 5
void moveLegs2(){
  for(int i = 0; i < 80; i++){
    B.write(Down + i);
    C.write(Down_2 + i);
    A.write(Mid - 40 + 0.5 * i);
    H.write(Up - i);
    I.write(Up_2 - i);
    G.write(Mid - 40 + 0.5 * i);
    P.write(Down + i);
    Q.write(Down_2 + i);    
    O.write(Mid + 40 - 0.5 * i);
    delay(10);
  }
  for(int i = 0; i < 80; i++){
    B.write(Down + 80 - i);
    C.write(Down_2 + 80 - i);
    A.write(Mid + 0.5 * i);
    H.write(Up - 80 + i);
    I.write(Up_2 - 80 + i);
    G.write(Mid + 0.5 * i);
    P.write(Down + 80 - i);
    Q.write(Down_2 + 80 - i);
    O.write(Mid - 0.5 * i);
    delay(10);
  }
}

// Set legs in starting step position

void setPosition1(){
  for(int i = 0; i < 40; i++){
    A.write(130 - i);
    G.write(130 - i);
    O.write(50 + i);
    D.write(90 - i);
    L.write(90 + i);
    R.write(90 + i);
    delay(10);
  }
}

void setPosition2(){
  for(int i = 0; i < 50; i++){
    A.write(90 - i);
    G.write(90 - i);
    O.write(90 + i);
    D.write(130 - i);
    L.write(50 + i);
    R.write(50 + i);
    delay(10);
  }
}

void moveForward(){
  if(firstStep == true){
    halfStep();
    firstStep = false;
  }
  setPosition1();
  moveLegs1();
  setPosition2();
  if(lastStep == true){
    halfStep2();
  }
  else{
    moveLegs2();
  }
  
}

void turnLeft(){

}

void turnRight(){

}

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  A.attach(2);
  B.attach(3);
  C.attach(4);

  D.attach(5);
  E.attach(6);
  F.attach(7);

  G.attach(8);
  H.attach(9);
  I.attach(10);

  L.attach(11);
  M.attach(12);
  N.attach(13);

  O.attach(16);
  P.attach(17);
  Q.attach(18);

  R.attach(19);
  S.attach(20);
  T.attach(21);

  A.write(A_Start);
  B.write(B_Start);
  C.write(C_Start);

  D.write(D_Start);
  E.write(E_Start);
  F.write(F_Start);

  G.write(G_Start);
  H.write(H_Start);
  I.write(I_Start);

  L.write(L_Start);
  M.write(M_Start);
  N.write(N_Start);

  O.write(O_Start);
  P.write(P_Start);
  Q.write(Q_Start);

  R.write(R_Start);
  S.write(S_Start);
  T.write(T_Start);

  delay(10);
}
void loop() {
  data = bluetooth.read();
  if(data == 'W'){
    do{
      moveForward();
    
    }while(bluetooth.read() != 'T');
    lastStep = true;
    moveForward();
    lastStep = false;
    firstStep = true;
  }

}
