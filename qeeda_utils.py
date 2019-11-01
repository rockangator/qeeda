
## import libraries
import config
import serial

'''
Utilities for main code.

Includes:
- ToF Derivatives
- Distance calculation
- Location calculation
'''

def send_rf(sertx, msg):
    print(msg.encode())
    sertx.write(msg.encode())
    #ser.write('A'.encode())

def recv_rf(serrx):
    print('aara')
    read_serial=serrx.readline()
    print(read_serial)
    recv_msg = str(read_serial)[2:4]
    print(recv_msg)
    return recv_msg

def getDist(f_tof):
    '''Calculating the distance using D = c x t, where c is speed of light
    and t is time taken'''

    return ((config.speedOfLight) * f_tof) / 2

def getLoc():
    '''Calculating the location from the list of distances'''
