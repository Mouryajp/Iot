int ir_sensor = 7;
int buz = 6;

void setup() {
  pinMode(ir_sensor,INPUT);
  pinMode(buz,OUTPUT);

}

void loop() {
  int data = digitalRead(ir_sensor);
  Serial.println(data);
  if(data == 0)
    digitalWrite(buz, HIGH);
  else
    digitalWrite(buz, LOW);
}
