
## import libraries
import time
import qeeda_utils as qtils
import serial

tof_list_bkp = [0.0,0.0,0.0,0.0]
##main
def mmain():

    tof_list = []

    for i in range(4):
        ## trigger transmitter
        t1 = time.time()

        ## send message
        qtils.send_rf(serTX, str(i+1))
        print('sent')
        
        ## recieve and check feedback
        recv_msg = qtils.recv_rf(serRX)
        print('lol')
        if recv_msg != 'A'+str(i+1) :
            t2 = tof_list_bkp[i]
        else:
            t2 = time.time()

        ## get the total time of flight
        tof = t2 - t1

        tof_list.append(tof)

    tof_list_bkp = tof_list
    
    ## calculate distances
    dist_tof = []
    for j in tof_list:
        dist_tof.append(qtils.getDist(j))

    ## finding the coordinates
    #return qtils.getLoc(listOfDist)
    return(dist_tof)

serTX = serial.Serial('COM21', 115200)
serRX = serial.Serial('COM20', 115200)
print(mmain())
