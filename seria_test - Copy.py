import serial
import time
import config

sertx = serial.Serial('COM21', 115200)

while 1:
    for i in range(4):
        msg = str(i+1)
        print('sending: ',msg.encode())
        
        config.msgstat = 'A' + msg
        print(config.msgstat)
        print(type(config.msgstat))
        config.t1 = time.time()
        sertx.write(msg.encode())
        time.sleep(2)
    
