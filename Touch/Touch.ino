int touch = 7;
int out = 42;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(touch, INPUT);
  pinMode(out, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(touch);

  Serial.println(data);

  if (data == 1) {
    if (count == 0) {
      digitalWrite(out, HIGH);
      count = 1;
    } else if (count == 1) {
      digitalWrite(out, LOW);
      count = 0;
    }
    // Delay to avoid rapid multiple detections during one touch
    
  }
}