#include <IRremote.h>

const int RECV_PIN = 12;
IRrecv irrecv(RECV_PIN);
decode_results results;

// Motor A
int IN1 = 7;
int IN2 = 8;

// Motor B
int IN3 = 4;
int IN4 = 11;

void stop() {
  // Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forward() {
  // Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse() {
  // Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
}

void leftTurn() {
  // Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
}

void rightTurn() {
  // Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  
}

void leftSpin() {
  // Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  // Motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
}

void rightSpin() {
  // Motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
}

void setup() {
  //IR remote
  Serial.begin(19200);
  Serial.println("Startup");
  irrecv.enableIRIn();
  irrecv.blink13(true);

  //motor inputs on board
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stop();
}

void loop() {
  if (irrecv.decode(&results)) {

    //if (results.value ==  0XFFFFFFFF)
      //results.value = key_value;
   
    switch (results.value) {
     
      //move forward
      case 2724004350:  //up arrow button
      forward();
        //Serial.println("^");
        //break;
     
      //move reverse
      case 2724036990:  //down arrow button
      reverse();
        //Serial.println("?");
        //break;
     
      //turn left
      case 2724039285:  //left arrow button
      leftTurn();
        //Serial.println("<");
        //break;

      //turn right
      case 2724049485:  //right arrow button
      rightTurn();  
        //Serial.println(">");
        //break;
    }
    key_value = results.value;
    irrecv.resume();
  }
  //forward();
  //delay(2000);
  //stop();
  //delay(2000);
}
