
 #include <AFMotor.h>
#include <Servo.h> 

//create two motor objects
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
//create lance objecy
Servo lance;

#include <Mailbox.h>

void setup() {
  // Initialize Bridge and Mailbox
  Bridge.begin();
  Mailbox.begin();

  // Initialize Console
  Console.begin();
  //set motor speed
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  //attach lance
  lance.attach(10);

  // Wait until a Console Monitor is connected.
  while (!Console);
    Console.println("Mailbox Read Message\n");
    Console.println("The incoming messages will be shown below.\n");
}

void loop() {
  String message;
  
  // if there is a message in the Mailbox
  if (Mailbox.messageAvailable()) {
    // read all the messages present in the queue
    while (Mailbox.messageAvailable()) {
      Mailbox.readMessage(message);
      Console.println(message);
    }

    Console.println(" ");
  }

  //oscillate lance
  int pos;
  for (pos = 280; pos >= 200; pos -= 5){

    lance.write(pos);

    
    delay(5);
    
  }

//states for movement and speed
#define FORWARDSTATE 1
#define BACKWARDSTATE 2
#define LEFTTURNSTATE 3
#define RIGHTTURNSTATE 4
#define RELEASESTATE 5
#define FIRST 6
#define SECOND 7
#define THIRD 8
#define FOURTH 9
#define FIFTH 10


int state;

if(message == "forward"){
  state = FORWARDSTATE;
}

if(message == "back"){
  state = BACKWARDSTATE;
}
if(message == "left"){
  state = LEFTTURNSTATE;
}
if(message == "right"){
  state = RIGHTTURNSTATE;
}
if(message == "stop"){
  state = RELEASESTATE;
}
if(message == "1st"){
  state = FIRST;
}

if(message == "2nd"){
  state = SECOND;
}
if(message == "3rd"){
  state = THIRD;
}
if(message == "4th"){
  state = FOURTH;
}
if(message == "5th"){
  state = FIFTH;
}

  switch(state){
    case FORWARDSTATE:
      if(message == "forward"){
          motor1.run(FORWARD);
          motor2.run(FORWARD);
      }
      break;
    case BACKWARDSTATE:
      if(message == "back"){
          motor1.run(BACKWARD);
          motor2.run(BACKWARD);
      }
      break;
    case LEFTTURNSTATE:
      if(message == "left"){
          motor1.run(BACKWARD);
          motor2.run(FORWARD);
      }
      break;
    case RIGHTTURNSTATE:
      if(message == "right"){
          motor1.run(FORWARD);
          motor2.run(BACKWARD);
      }
      break;
    case RELEASESTATE:
      if(message == "stop"){
          motor1.run(RELEASE);
          motor2.run(RELEASE);
      }
      break;
      case FIRST:
      if(message == "1st"){
          motor1.setSpeed(50);
          motor2.setSpeed(50);
      }
      break;
    case SECOND:
      if(message == "2nd"){
          motor1.setSpeed(100);
          motor2.setSpeed(100);
      }
      break;
    case THIRD:
      if(message == "3rd"){
          motor1.setSpeed(150);
          motor2.setSpeed(150);
      }
      break;
    case FOURTH:
      if(message == "4th"){
          motor1.setSpeed(200);
          motor2.setSpeed(200);
      }
      break;
    case FIFTH:
      if(message == "5th"){
          motor1.setSpeed(250);
          motor2.setSpeed(250);
      }
      break;
      
  }
  }

