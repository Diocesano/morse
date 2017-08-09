//MORSE

#define buzzer 9
#define led 8

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  if (Serial.available ()) {
    int auxiliar = Serial.read();
    Serial.println(auxiliar);
    executar(auxiliar);
  }
}

void ponto() {
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}

void traco() {
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(750);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
void A() {
  ponto();
  traco();
  delay(4000);
}
void B() {
  traco();
  ponto();
  ponto();
  ponto();
  delay(4000);
}
void C() {
  traco();
  ponto();
  traco();
  ponto();
  delay(4000);
}
void D() {
  traco();
  ponto();
  ponto();
  delay(4000);
}
void E() {
  ponto();
  delay(4000);
}
void efe() {
  ponto();
  ponto();
  traco();
  ponto();
  delay(4000);
}
void G() {
  traco();
  traco();
  ponto();
  delay(4000);
}

void H() {
  ponto();
  ponto();
  ponto();
  ponto();
  delay(4000);
}

void I() {
  ponto();
  ponto();
  delay(4000);
}
void J() {
  ponto();
  traco();
  traco();
  traco();
  delay(4000);
}

void K() {
  traco();
  ponto();
  traco();
  delay(4000);
}
void L() {
  ponto();
  traco();
  ponto();
  ponto();
  delay(4000);
}

void M() {
  traco();
  traco();
  delay(4000);
}

void N() {
  traco();
  ponto();
  delay(4000);
}

void O() {
  traco();
  traco();
  traco();
  delay(4000);
}
void P() {
  ponto();
  traco();
  traco();
  ponto();
  delay(4000);
}

void Q() {
  traco();
  traco();
  ponto();
  traco();
  delay(4000);
}

void R() {
  ponto();
  traco();
  ponto();
  delay(4000);
}

void S() {
  ponto();
  ponto();
  ponto();
  delay(4000);
}

void T() {
  traco();
  delay(4000);
}

void U() {
  ponto();
  ponto();
  traco();
  delay(4000);
}

void V() {
  ponto();
  ponto();
  ponto();
  traco();
  delay(4000);
}

void W() {
  ponto();
  traco();
  traco();
  delay(4000);
}

void X() {
  traco();
  ponto();
  ponto();
  traco();
  delay(4000);
}

void Y() {
  traco();
  ponto();
  traco();
  traco();
  delay(4000);
}

void Z() {
  traco();
  traco();
  ponto();
  ponto();
  delay(4000);
}

void executar(int x) {
  if (x == 97) {
    A();
  }
  else if (x == 98) {
    B();
  }
  else if (x == 99) {
    C();
  }
  else if (x == 100) {
    D();
  }
  else if (x == 101) {
    E();
  }
  else if (x == 102) {
    efe();
  }
  else if (x == 103) {
    G();
  }
  else if (x == 104) {
    H();
  }
  else if (x == 105) {
    I();
  }
  else if (x == 106) {
    J();
  }
  else if (x == 107) {
    K();
  }
  else if (x == 108) {
    L();
  }
  else if (x == 109) {
    M();
  }
  else if (x == 110) {
    N();
  }
  else if (x == 111) {
    O();
  }
  else if (x == 112) {
    P();
  }
  else if (x == 113) {
    Q();
  }
  else if (x == 114) {
    R();
  }
  else if (x == 115) {
    S();
  }
  else if (x == 116) {
    T();
  }
  else if (x == 117) {
    U();
  }
  else if (x == 118) {
    V();
  }
  else if (x == 119) {
    W();
  }
  else if (x == 120) {
    X();
  }
  else if (x == 121) {
    Y();
  }
  else if (x == 122) {
    Z();
  }
}
