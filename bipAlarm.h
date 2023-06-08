void frequency_1() {
  for (int i = 0; i <80; i ++) {
    digitalWrite (pinBuzzer, HIGH);
    delay (1);
    digitalWrite (pinBuzzer, LOW);
    delay (1);
  }
}

void frequency_2() {
  for (int i = 0; i <100; i ++) {
    digitalWrite (pinBuzzer, HIGH);
    delay (2); // delay 2ms
    digitalWrite (pinBuzzer, LOW);
    delay (2); // delay 2ms
  }
}
