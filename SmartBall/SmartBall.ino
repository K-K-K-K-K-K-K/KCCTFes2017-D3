/* ピン番号の設定 -------------- */
const int tgrsw        = 2;

const int elemgt1A  = 3;
const int elemgt1B  = 4;
const int led1           = 5;

const int elemgt2A  = 7;
const int elemgt2B  = 8;
const int led2           = 6;
/* ------------------------------------ */

void setup() {
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
  if (digitalRead(tgrsw) == LOW) {
    Serial.println("----- Normal-Mode --------------");
    while (digitalRead(tgrsw) == LOW) {
      module1(true);
      module2(false);
      Serial.print("module1: ON, module2: OFF - ");
      Serial.println(millis());
      delay(1000);

      if (checkControlModeRequest()) {
        controlMode();
        Serial.println("----- Normal-Mode --------------");
      }

      module1(false);
      module2(true);
      Serial.print("module1: OFF, module2: ON - ");
      Serial.println(millis());
      delay(1000);

      if (checkControlModeRequest()) {
        controlMode();
        Serial.println("----- Normal-Mode --------------");
      }
    }
  } else {
    Serial.println("----- Emergency-Mode ----------");
    xseq();
    while (digitalRead(tgrsw) == HIGH) {
      led(true);
      Serial.print("LED1: ON, LED2: OFF - ");
      Serial.println(millis());
      delay(1000);

      if (checkControlModeRequest()) {
        controlMode();
        Serial.println("----- Emergency-Mode ----------");
      }

      led(false);
      Serial.print("LED1: OFF, LED2: ON - ");
      Serial.println(millis());
      delay(1000);

      if (checkControlModeRequest()) {
        controlMode();
        Serial.println("----- Emergency-Mode ----------");
      }
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

boolean checkControlModeRequest() {
  if (Serial.available() > 0) {
    if (Serial.readString() == "!deprive") {
      return true;
    }
  }
  return false;
}

void controlMode() {
  module1(false);
  module2(false);
  Serial.println("--- Controll-Mode ------------");
  Serial.println("This system is under the computer control now.");
  Serial.println("example: !set {elemgt{1{A | B} | 2{A | B}} | led{1 | 2}} {ON | OFF}");
  Serial.println("         !return");
  for (;;) {
    if (Serial.available() > 0) {
      String input = Serial.readString();
      if (input == "!set elemgt1A ON") {
        digitalWrite(elemgt1A, HIGH);
        Serial.print("elemgt1A: ON - ");
        Serial.println(millis());
      } else if (input == "!set elemgt1A OFF") {
        digitalWrite(elemgt1A, LOW);
        Serial.print("elemgt1A: OFF - ");
        Serial.println(millis());
      } else if (input == "!set elemgt1B ON") {
        digitalWrite(elemgt1B, HIGH);
        Serial.print("elemgt1B: ON - ");
        Serial.println(millis());
      } else if (input == "!set elemgt1B OFF") {
        digitalWrite(elemgt1B, LOW);
        Serial.print("elemgt1B: OFF - ");
        Serial.println(millis());
      } else if (input == "!set led1 ON") {
        digitalWrite(led1, HIGH);
        Serial.print("LED1: ON - ");
        Serial.println(millis());
      } else if (input == "!set led1 OFF") {
        digitalWrite(led1, LOW);
        Serial.print("LED1: OFF - ");
        Serial.println(millis());
      } else if (input == "!set elemgt2A ON") {
        digitalWrite(elemgt2A, HIGH);
        Serial.print("elemgt2A: ON - ");
        Serial.println(millis());
      } else if (input == "!set elemgt2A OFF") {
        digitalWrite(elemgt2A, LOW);
        Serial.print("elemgt2A: OFF - ");
        Serial.println(millis());
      } else if (input == "!set elemgt2B ON") {
        digitalWrite(elemgt2B, HIGH);
        Serial.print("elemgt2B: ON - ");
        Serial.println(millis());
      } else if (input == "!set elemgt2B OFF") {
        digitalWrite(elemgt2B, LOW);
        Serial.print("elemgt2B: OFF - ");
        Serial.println(millis());
      } else if (input == "!set led2 ON") {
        digitalWrite(led2, HIGH);
        Serial.print("LED2: ON - ");
        Serial.println(millis());
      } else if (input == "!set led2 OFF") {
        digitalWrite(led2, LOW);
        Serial.print("LED2: OFF - ");
        Serial.println(millis());
      } else if (input == "!return") {
        Serial.println("Returned the control to the microcomputer.");
        break;
      } else {
        Serial.print("Incorrect: ");
        Serial.println(input);
      }
    }
  }
}

