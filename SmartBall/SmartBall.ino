void setup() {
  pinMode(2, INPUT); // toggle switch
  pinMode(5, OUTPUT); // electromagnet
  //pinMode(7, OUTPUT); // LED

  pinMode(LED_BUILTIN, OUTPUT); // debug
}

void loop() {
  if (digitalRead(2) == LOW) {
    digitalWrite(5, HIGH);
//    digitalWrite(7, HIGH);
    while (digitalRead(2) == LOW) { // from debug
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(800);
    } // to debug
  } else {
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(LED_BUILTIN, HIGH); // debug
    while (digitalRead(2) == HIGH);
  }
}


