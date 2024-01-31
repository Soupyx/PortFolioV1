int relaisPlus = 12;

void setup() {                
  pinMode(relaisPlus, OUTPUT);     
}

void loop() {
  digitalWrite(relaisPlus, HIGH);
  delay(10000);
  digitalWrite(relaisPlus, LOW);
  delay(10000);
}