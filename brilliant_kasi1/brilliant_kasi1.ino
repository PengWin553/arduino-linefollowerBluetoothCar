#include <AFMotor.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetoothSerial(9, 10); 
#define lefts A0
#define rights A1
char command;
bool mode = false;
// AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
// AF_DCMotor motor4(4, MOTOR34_1KHZ);
void setup() {
  // motor1.setSpeed(180);
  motor2.setSpeed(180);
  motor3.setSpeed(180);
  // motor4.setSpeed(180);
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  Serial.begin(9600);
  bluetoothSerial.begin(9600); 
}
void loop(){
  if (bluetoothSerial.available() > 0) {
    command = bluetoothSerial.read();
    Stop(); 
    switch (command) {
      case 'F':
        forward_BT();
        break;
      case 'B':
        backward_BT();
        break;
      case 'L':
        turnLeft();
        break;
      case 'R':
        turnRight();
        break;
      case 'X':
        mode = true;
        break;
      case 'x':
        mode = false;
    }
      if(mode == true){
        if((digitalRead(rights) == 0)&&(digitalRead(lefts) == 0)){forward();}
        if((digitalRead(rights) == 1)&&(digitalRead(lefts) == 0)){turnLeft();}
        if((digitalRead(rights) == 0)&&(digitalRead(lefts) == 1)){turnRight();}
        if((digitalRead(rights) == 1)&&(digitalRead(lefts) == 1)){Stop();} 
  }
    if(mode == false){
      loop();
    }
  }
}
void turnRight(){ 
// motor1.setSpeed(255);
// motor1.run(FORWARD);
motor2.setSpeed(255);
motor2.run(FORWARD);
motor3.setSpeed(255);
motor3.run(BACKWARD);
// motor4.setSpeed(255);
// motor4.run(BACKWARD);
}
void turnLeft(){
// motor1.setSpeed(255);
// motor1.run(BACKWARD);
motor2.setSpeed(255);
motor2.run(BACKWARD);
motor3.setSpeed(255);
motor3.run(FORWARD);
// motor4.setSpeed(255);
// motor4.run(FORWARD);
}
void backward(){ 
// motor1.setSpeed(255);
// motor1.run(FORWARD);
motor2.setSpeed(200);
motor2.run(FORWARD);
motor3.setSpeed(200);
motor3.run(FORWARD);
// motor4.setSpeed(255);
// motor4.run(FORWARD);
}
void forward(){ 
// motor1.setSpeed(255);
// motor1.run(BACKWARD);
motor2.setSpeed(190);
motor2.run(BACKWARD);
motor3.setSpeed(190);
motor3.run(BACKWARD);
// motor4.setSpeed(255);
// motor4.run(BACKWARD);
}
void Stop(){
// motor1.setSpeed(0);
// motor1.run(RELEASE);
motor2.setSpeed(0);
motor2.run(RELEASE);
motor3.setSpeed(0);
motor3.run(RELEASE);
// motor4.setSpeed(0);
// motor4.run(RELEASE);
}
void backward_BT(){ 
// motor1.setSpeed(255);
// motor1.run(FORWARD);
motor2.setSpeed(255);
motor2.run(FORWARD);
motor3.setSpeed(255);
motor3.run(FORWARD);
// motor4.setSpeed(255);
// motor4.run(FORWARD);
}
void forward_BT(){ 
// motor1.setSpeed(255);
// motor1.run(BACKWARD);
motor2.setSpeed(255);
motor2.run(BACKWARD);
motor3.setSpeed(255);
motor3.run(BACKWARD);
// motor4.setSpeed(255);
// motor4.run(BACKWARD);
}