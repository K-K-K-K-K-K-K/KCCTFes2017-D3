const int tgrsw        = 0;

const int elemgt1A  = 1;
const int elemgt1B  = 2;
const int led1           = 3;

const int elemgt2A  = 4;
const int elemgt2B  = 5;
const int led2           = 6;

void setup() {
  pinMode(tgrsw, INPUT);

  pinMode(elemgt1A, OUTPUT);
  pinMode(elemgt1B, OUTPUT);
  //pinMode(led1, OUTPUT);

  //pinMode(elemgt2A, OUTPUT);
  //pinMode(elemgt2B, OUTPUT);
  //pinMode(led2, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT); // debug
}

void loop() {
  if (digitalRead(tgrsw) == LOW) {
    while (digitalRead(tgrsw) == LOW) {
      module1(true);
      module2(false);
      digitalWrite(LED_BUILTIN, HIGH); // debug
      delay(3000);
      module1(false);
      module1(true);
      digitalWrite(LED_BUILTIN, LOW); // debug
      delay(3000);
    }
  } else {
    xseq();
    digitalWrite(LED_BUILTIN, HIGH); // debug
    while (digitalRead(tgrsw) == HIGH) {
      //digitalWrite(led1, HIGH);
      //digitalWrite(led2, LOW);
      delay(3000);
      //digitalWrite(led1, LOW);
      //digitalWrite(led2, HIGH);
      delay(3000);
    }
  }
}

void module1(bool b) {
      digitalWrite(elemgt1A, b ? HIGH : LOW);
      digitalWrite(elemgt1B, b ? HIGH : LOW);
//      digitalWrite(led1, b ? HIGH : LOW);
}

void module2(bool b) {
//      digitalWrite(elemgt2A, b ? HIGH : LOW);
//      digitalWrite(elemgt2B, b ? HIGH : LOW);
//      digitalWrite(led2, b ? HIGH : LOW);
}

void xseq() {
      digitalWrite(elemgt1A, HIGH);
      digitalWrite(elemgt1B, HIGH);
//      digitalWrite(elemgt2A, HIGH);
//      digitalWrite(elemgt2B, HIGH);
}

