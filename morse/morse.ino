/*

  #Título: Morse

  #Autores: Maiara Torres - 2015774@aluno.diocesanocaruaru.g12.br
            Alisson Sherman - 2014059@aluno.diocesanocaruaru.g12.br
            Caio José - 32439@aluno.diocesanocaruaru.g12.br
            Guilherme Liberato - 35715@aluno.diocesanocaruaru.g12.br

  #Orientador: Prof. Diógenes Souza - diogenessouza@diocesanocaruaru.g12.br

  #Repositório do projeto no GitHub: https://github.com/Diocesano/morse


  #Descrição:
  Este projeto funciona a partir do aplicativo android
  que desenvolvemos que compreende o que foi falado e
  envia a palavra via bluetooth para o módulo bluetooth
  conectado à porta de comunicação serial da placa Arduino.
  O Arduino, por meio desta programação, converte a palavra
  para código Morse através de um led intermitente e também
  de som através de um buzzer. Como complemento, aparece no
  visor lcd o código graficamente reprentado.

  #Componentes:
  ->1 placa baseada no Arduino Uno R3, utilizando o
      microcontrolador Atmel Atmega328p
  ->1 Módulo bluetooth HC-06
  ->1 Led difuso 5mm na cor vermelha
  ->1 Buzzer 5v
  ->1 Display LCD 16x2 com módulo I2C

  #Conexões:

                                      +-----+
         +----[PWR]-------------------| USB |--+
         |                            +-----+  |
         |                                     |
         |                           A5/SCL[ ] |
         |                           A4/SDA[ ] |
         |                             AREF[ ] |
         |                              GND[ ] |
         | [ ]N/C                    SCK/13[ ] |
         | [ ]IOREF                 MISO/12[ ] |
         | [ ]RST                   MOSI/11[ ]~|
         | [ ]3V3    +---+               10[ ]~|
         | [ ]5v    -| A |-               9[B]~|
         | [ ]GND   -| R |-               8[C] |
         | [ ]GND   -| D |-                    |
         | [ ]Vin   -| U |-               7[ ] |
         |          -| I |-               6[ ]~|
         | [ ]A0    -| N |-               5[ ]~|
         | [ ]A1    -| O |-               4[ ] |
         | [ ]A2     +---+           INT1/3[ ]~|
         | [ ]A3                     INT0/2[ ] |
         | [D]A4/SDA                   TX>1[F] |
         | [E]A5/SCL                   RX<0[G] |
         |                                     |
         |  UNO_R3                 ____________/
          \_______________________/

  B: pino positivo do buzzer
  C: pino positivo do led
  D: pino SDA do display LCD
  E: pino SCL do display LCD
  F: pino RXD do módulo HC-06
  G: pino TXD do módulo HC-06


  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
    LICENÇA - Copyright 2017 Maiara, Alisson, Caio, Guilherme e Diógenes
  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   

    Este programa é um software livre; você pode redistribuí-lo e/ou 
    modificá-lo dentro dos termos da Licença Pública Geral GNU como 
    publicada pela Fundação do Software Livre (FSF); na versão 3 da 
    Licença, ou (na sua opinião) qualquer versão.

    Este programa é distribuído na esperança de que possa ser útil, 
    mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
    a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
    Licença Pública Geral GNU para maiores detalhes.

    Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
    com este programa. Se não, veja <http://www.gnu.org/licenses/>.
  
  ------------------------------------------------------------------
*/


//bibliotecas
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

//determina em quais pinos o LCD será conectado
LiquidCrystal_I2C  lcd(0x27, 2, 1, 0, 4, 5, 6, 7);

//constantes
#define buzzer 9
#define led 8

void setup() {
  Serial.begin(9600); //inicia a porta serial
  pinMode(buzzer, OUTPUT); //configura o pino do buzzer como saída
  pinMode(led, OUTPUT); //configura o pino do led como saída
  lcd.setBacklightPin(3, POSITIVE); //ativa o uso da luz de background do visor lcd
  lcd.setBacklight(HIGH); //acende a luz de background do visor lcd
  lcd.begin(16, 2); //inicia o visor lcd informando que são 16 caracteres e duas linhas
}

void loop() {

  if (Serial.available ()) {       //se algum dado for recebido na porta serial (pelo módulo bluetooth)
    int auxiliar = Serial.read();  // armazena na variável auxiliar a leitura da porta serial
    Serial.println(auxiliar);     //printa o valor da variável auxiliar (leitura da serial)
    executar(auxiliar);          //executa função "executar", que emite os códigos de cada letra recebida
    lcd.clear();                //limpa o visor depois de cada letra impressa no lcd
  }
}

void ponto() {              //função que emite o sinal referente ao ponto e o printa no visor lcd
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  lcd.print(". ");
  delay(300);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);

}

void traco() {            //função que emite o sinal referente ao traço e o printa no visor lcd
  digitalWrite(led, HIGH);
  digitalWrite(buzzer, HIGH);
  lcd.print("- ");
  delay(750);
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
  delay(1000);
}

//série de funções que executam os sinais referente a cada letra do código Morse (de A a Z)
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
  lcd.print("/");
  delay(4000);
}

//função executar, que confere o valor recebido pela serial e exceuta a função da letra correspondente ao código recebio
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
