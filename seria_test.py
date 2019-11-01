##import serial
##
##ser = serial.Serial('COM20', 115200)
##
##while(True):
##  read_serial=ser.readline()
##  a=str(read_serial)[2:4]
##  print(a)
##
##import serial
##ser = serial. Serial('COM21', 9600)
##ser.write('H'.encode())
##
##a = 10
##def x():
##  print(a)
## # print(b)
##
##
##x()

import time
import serial
import config

serrx = serial.Serial('COM20', 115200)

while 1:
    read_serial=serrx.readline()
    t2 = time.time()
    print(read_serial)
    recv_msg = str(read_serial)[2:4]
    print('recv_msg',recv_msg)
    print('msgstat', config.msgstat)
    if recv_msg == config.msgstat:
        config.t2 = t2
        print('t2',t2)
        print('t1',config.t1)
        print('time: ',config.t2-config.t1)
