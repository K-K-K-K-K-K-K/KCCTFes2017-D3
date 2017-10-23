void setup() {
  pinMode(2, INPUT); // toggle switch
  pinMode(5, OUTPUT); // electromagnet
  pinMode(7, OUTPUT); // LED

  pinMode(LED_BUILTIN, OUTPUT); // debug
}

void loop() {
  if (digitalRead(2) == HIGH) {
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    while (digitalRead(2) == HIGH) { // from debug
      digitalWrite(LED_BUILTIN, HIGH);
      delay(500);
      digitalWrite(LED_BUILTIN, LOW);
      delay(500);
    } // to debug
  } else {
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(LED_BUILTIN, HIGH); // debug
    while (digitalRead(2) == LOW);
  }
}


