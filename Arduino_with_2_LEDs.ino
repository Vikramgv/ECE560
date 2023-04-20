void setup() {
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  unsigned long timeBegin = micros();
  Serial.begin(9600);
  TCCR1A = 0;
  TCCR1B = bit(CS10);
  TCNT1 = 0;
  /* Code to measure: */
  PORTB = bit(5);
  unsigned int cycles = TCNT1;
  Serial.print("Number of Cycles: ");
  Serial.println(cycles - 1);
  Serial.print("Clock Cycle: ");
  Serial.println((float)(cycles - 1) / 16);
  Serial.print("microseconds");
  Serial.println();
  for (int i = 0; i < 500; i++)
  {
   digitalWrite(LED_BUILTIN, HIGH);
   digitalWrite(LED_BUILTIN, LOW);
  }
  unsigned long timeEnd = micros();
  unsigned long duration = timeEnd - timeBegin;
  double averageDuration = (double)duration / 1000.0;
  Serial.print("Digital write Time = ");
  Serial.println(averageDuration);
  Serial.print("microseconds");
  Serial.println();
}

void loop() {
  digitalWrite(9, HIGH);
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  delay(1000);
}