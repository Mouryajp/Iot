// //Reciever
// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
//   digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin
//   Serial.begin(9600); 
//   Serial1.begin(9600);            // initialize UART with baud rate of 9600
// }
// void loop() {
//   while (Serial1.available() >= 0) {
//     char receivedData = Serial1.read();   // read one byte from serial buffer and save to receivedData
//     Serial.println(Serial1.available());
//     if (receivedData == '1') {
//       digitalWrite(LED_BUILTIN, HIGH); // switch LED On
//     }
//     else if (receivedData == '0') {
//       digitalWrite(LED_BUILTIN, LOW);  // switch LED Off
//     }
//   }
// }

// // void setup() {
// //   pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
// //   digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

// //   Serial.begin(9600);               // initialize serial communication at 9600 bits per second
// //   Serial1.begin(9600);              // initialize UART with baud rate of 9600
// // }

// // void loop() {
// //   while (Serial1.available() > 0) { // Check if data is available to read from Serial1
// //     char receivedData = Serial1.read();   // Read one byte from serial buffer and save to receivedData
// //     Serial.println(Serial1.available());
// //     if (receivedData == '1') {
// //       digitalWrite(LED_BUILTIN, HIGH); // Switch LED On
// //       Serial.println("LED On");
// //     }
// //     else if (receivedData == '0') {
// //       digitalWrite(LED_BUILTIN, LOW);  // Switch LED Off
// //       Serial.println("LED Off");
// //     }
// //   }
// // }

//Transmittor
// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
//   digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

//   Serial.begin(9600);               // initialize serial communication at 9600 bits per second:
//   Serial1.begin(9600);            // initialize UART with baud rate of 9600
// }
// void loop() {
//   if (Serial.read() == '1'){
//     Serial1.println('1');
//     digitalWrite(LED_BUILTIN, HIGH);
//     Serial.println("LEDS ON");
//   }
//   else if (Serial.read() == '0'){
//     Serial1.println('0');
//     digitalWrite(LED_BUILTIN, LOW);
//     Serial.print("LEDS OFF");
//   }
// }


// void setup() {
//   pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
//   digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

//   Serial.begin(9600);               // initialize serial communication at 9600 bits per second:
//   Serial1.begin(9600);            // initialize UART with baud rate of 9600
// }

// void loop() {
//  // Check if data is available to read from Serial
//     char receivedChar = Serial.read(); // Read the incoming byte
//     if (receivedChar == '1') {
//       Serial1.println('1'); // Transmit data over Serial1 to another ESP32
//       digitalWrite(LED_BUILTIN, HIGH);
//       Serial.println("LEDs ON");
//     } else if (receivedChar == '0') {
//       Serial1.println('0'); // Transmit data over Serial1 to another ESP32
//       digitalWrite(LED_BUILTIN, LOW);
//       Serial.println("LEDs OFF");
//     }
//   }

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
  digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

  Serial.begin(9600);               // initialize serial communication at 9600 bits per second:
  Serial1.begin(9600);            // initialize UART with baud rate of 9600
}
void loop() {
  if (Serial.read() == '1'){
    Serial1.println('1');
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LEDS ON");
  }
  else if (Serial.read() == '0'){
    Serial1.println('0');
    digitalWrite(LED_BUILTIN, LOW);
    Serial.print("LEDS OFF");
  }
}
