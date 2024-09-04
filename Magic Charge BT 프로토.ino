#include <SoftwareSerial.h>

SoftwareSerial BTSerial(3, 4); //-->불투 시리얼 넘버

const int in1Pin = 7; 
const int in2Pin = 8; 

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  BTSerial.begin(9600);
  Serial.begin(9600); // 이거 체크 한번 해봐야함 ㅇㅇ 불투 모듈 시리얼 채널 송신 값 ==> 9600
}

void loop() {
  if (BTSerial.available()) {
    char command = BTSerial.read();
    Serial.println(command);

    switch (command) {
      case 'U': // 올라가는 기능
        digitalWrite(in1Pin, HIGH);
        digitalWrite(in2Pin, LOW);
        break;
      case 'D': // 내려감 기능
        digitalWrite(in1Pin, LOW);
        digitalWrite(in2Pin, HIGH);
        break;
      case 'S': // 정지 기능
        digitalWrite(in1Pin, LOW);
        digitalWrite(in2Pin, LOW);
        break;
    }
  }
}
