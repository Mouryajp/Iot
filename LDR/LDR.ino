int ldr = 7; 
int buz = 6;

void setup() {
  pinMode(ldr,INPUT);
  pinMode(buz,OUTPUT);
}

void loop() {
  int data = digitalRead(ldr);
  Serial.println(data);
  if(data == 0)
    digitalWrite(buz, HIGH);
  else
    digitalWrite(buz, LOW);

}
