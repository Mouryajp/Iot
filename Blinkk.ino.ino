//declaration
int led = BUILDIN_LED; //42
//setup
void setup() {
pinMode(led,OUTPUT);
}

//loop
void loop() {
digitalWrite(led, HIGH);
delay(2000);
digitalWrite(led, LOW);
delay(2000);
}
