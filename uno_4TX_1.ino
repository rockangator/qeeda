#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

//RH_ASK driver;
//RH_ASK driver(6000,D7,D8);
RH_ASK driver;

char incomingMsg;
int intmsg;
int c = 0;

int t1 = 2;
int t2 = 3;
int t3 = 4;
int t4 = 5;

void setup()
{
    //pinMode(LED_BUILTIN, OUTPUT);
    pinMode(t1 , OUTPUT);
    pinMode(t2 , OUTPUT);
    pinMode(t3 , OUTPUT);
    pinMode(t4 , OUTPUT);

    digitalWrite(t1, HIGH);
    digitalWrite(t2, HIGH);
    digitalWrite(t3, HIGH);
    digitalWrite(t4, HIGH);
    
    Serial.begin(115200);    // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    
    Serial.println("TX setup done.");
}

void loop()
{
    //Serial.print("c: ");
    //Serial.println(c);
    
    if (Serial.available() > 0) {
    incomingMsg = Serial.read();
    Serial.println(incomingMsg);
    intmsg  = incomingMsg - '0';
    Serial.println(intmsg);

    if (intmsg == 1){digitalWrite(t1, LOW);
      const char *msg1 = "A1";
      driver.send((uint8_t *)msg1, strlen(msg1));
      driver.waitPacketSent();
      digitalWrite(t1, HIGH);
      Serial.println("T1");}
    if (intmsg == 2){digitalWrite(t2, LOW);
      const char *msg2 = "A2";
      driver.send((uint8_t *)msg2, strlen(msg2));
      driver.waitPacketSent();
      digitalWrite(t2, HIGH);
      Serial.print("T2");}
    if (intmsg == 3){digitalWrite(t3, LOW);
      const char *msg3 = "A3";
      driver.send((uint8_t *)msg3, strlen(msg3));
      driver.waitPacketSent();
      digitalWrite(t3, HIGH);
      Serial.print("T3");}
    if (intmsg == 4){digitalWrite(t4, LOW);
      const char *msg4 = "A4";
      driver.send((uint8_t *)msg4, strlen(msg4));
      driver.waitPacketSent();
      digitalWrite(t4, HIGH);
      Serial.print("T4");}
    
//    switch (intmsg) {
//    case 1:
//      digitalWrite(t1, LOW);
//      const char *msg1 = "A1";
//      driver.send((uint8_t *)msg1, strlen(msg1));
//      driver.waitPacketSent();
//      digitalWrite(t1, HIGH);
//      Serial.println("T1");
//      break;
//    case 2:
//      digitalWrite(t2, LOW);
//      const char *msg2 = "A2";
//      driver.send((uint8_t *)msg2, strlen(msg2));
//      driver.waitPacketSent();
//      digitalWrite(t2, HIGH);
//      Serial.print("T2");
//      break;
//    case 3:
//      digitalWrite(t3, LOW);
//      const char *msg3 = "A3";
//      driver.send((uint8_t *)msg3, strlen(msg3));
//      driver.waitPacketSent();
//      digitalWrite(t3, HIGH);
//      Serial.print("T3");
//      break;
//    case 4:
//      digitalWrite(t4, LOW);
//      const char *msg4 = "A4";
//      driver.send((uint8_t *)msg4, strlen(msg4));
//      driver.waitPacketSent();
//      digitalWrite(t4, HIGH);
//      Serial.print("T4");
//      break;
//    default:
//      Serial.print("fcuk ho gya");
//      break;
//    }
    }

    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(100);
    //driver.waitPacketSent();
    //digitalWrite(LED_BUILTIN, LOW);
    //delay(1000);
    //c++;
    
}
