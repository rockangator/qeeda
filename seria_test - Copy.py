import serial

def send_rf(sertx, msg):
    print(msg.encode())
    sertx.write(msg.encode())
    #ser.write('A'.encode())

serTX = serial.Serial('COM21', 115200)

send_rf(serTX, '1')
