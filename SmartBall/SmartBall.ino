#include <Thread.h>
#include <ThreadController.h>

/* ピン番号の設定 -------------- */
const int tgrsw        = 2;

const int elemgt1A  = 3;
const int elemgt1B  = 4;
const int led1           = 5;

const int elemgt2A  = 7;
const int elemgt2B  = 8;
const int led2           = 6;
/* ------------------------------------ */

ThreadController control = ThreadController();
Thread mainTh = Thread();

void setup() {https://github.com/kcct-dk/KCCTFes2017-D3/branches/all
  pinMode(tgrsw, INPUT);

  pinMode(elemgt1A, OUTPUT);
  pinMode(elemgt1B, OUTPUT);
  pinMode(led1, OUTPUT);

  pinMode(elemgt2A, OUTPUT);
  pinMode(elemgt2B, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  mainTh.onRun(mainFn);
  mainTh.run();
  Serial.println("test");
}

/* main -------------------------------------------------------------------------------------------------------------- */
void mainFn() {
  if (digitalRead(tgrsw) == LOW) {
      Serial.println("----- Normal-Mode ----------");
    while (digitalRead(tgrsw) == LOW) {
      module1(true);
      module2(false);
      Serial.print("module1: ON, module2: OFF - ");
      Serial.println(millis());
      delay(1000);
      module1(false);
      module2(true);
      Serial.print("module1: OFF, module2: ON - ");
      Serial.println(millis());
      delay(1000);
    }
  } else {
    Serial.println("----- Emergency-Mode ----------");
    xseq();
    while (digitalRead(tgrsw) == HIGH) {
      led(true);
      Serial.print("LED1: ON, LED2: OFF - ");
      Serial.println(millis());
      delay(1000);
      led(false);
      Serial.print("LED1: OFF, LED2: ON - ");
      Serial.println(millis());
      delay(1000);
    }
  }
}

void module1(bool b) {
      digitalWrite(elemgt1A, b ? HIGH : LOW);
      digitalWrite(elemgt1B, b ? HIGH : LOW);
      digitalWrite(led1, b ? HIGH : LOW);
}

void module2(bool b) {
      digitalWrite(elemgt2A, b ? HIGH : LOW);
      digitalWrite(elemgt2B, b ? HIGH : LOW);
      digitalWrite(led2, b ? HIGH : LOW);
}

void xseq() {
      digitalWrite(elemgt1A, HIGH);
      digitalWrite(elemgt1B, HIGH);
      digitalWrite(elemgt2A, HIGH);
      digitalWrite(elemgt2B, HIGH);
}

void led(bool b) {
  digitalWrite(led1, b ? HIGH : LOW);
  digitalWrite(led2, !b ? HIGH : LOW);
}
/* ------------------------------------------------------------------------------------------------------------------- */

