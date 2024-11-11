import logging
import copy
import sys
import math

logging.basicConfig(stream=sys.stderr, level=logging.DEBUG)

#def solve(firstLine):
def solve(formatStr, timeStr):

    if int(timeStr[3]) > 5 :
        timeStr =  timeStr[:3] + "0" + timeStr[4:]
        
    if formatStr == 24:
        if int(timeStr[0]) > 2:
            timeStr = "0" + timeStr[1:]
        elif int(timeStr[0]) == 2 and int(timeStr[1]) > 4:
            timeStr = timeStr[0] +  "0" + timeStr[2:]

    if formatStr == 12:
        if int(timeStr[0]) > 1:
            if int(timeStr[1]) == 0:
                timeStr = "1" + timeStr[1:]
            else:
                timeStr = "0" + timeStr[1:]
        elif int(timeStr[0]) == 1 and int(timeStr[1]) > 2:
            timeStr = "0" + timeStr[1:]
        elif int(timeStr[0]) == 0 and int(timeStr[1]) == 0:
            timeStr = "01" + timeStr[2:]

    return timeStr
    

            
            
    
    

def main():
    formatStr = int(input())

        
    print(solve(formatStr, input()))
    

def log(*message):
    logging.debug(message)
    
if __name__ == "__main__":
    main()
 
