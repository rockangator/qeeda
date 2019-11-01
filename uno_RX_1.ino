#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{
    Serial.begin(115200);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");

    //delay(1000);
    //Serial.println("RX setup done.");
}

void loop()
{
    uint8_t buf[2];
    uint8_t buflen = sizeof(buf);
    
    if (driver.recv(buf, &buflen))
    {
        Serial.println((char*)buf);    
    }
}


//void loop()
//{
//byte message[VW_MAX_MESSAGE_LEN];
//byte messageLength = VW_MAX_MESSAGE_LEN;
//
//if (vw_get_message(message, &messageLength))
//{
// // Serial.println();
//for (int i = 0; i < messageLength; i++)
//{
//Serial.write(message[i]);
//}
//Serial.println();
//}
//}
