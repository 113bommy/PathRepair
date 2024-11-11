import math
def baseCompare():
    baseXInfo=input().split()
    baseXDigits=input().split()
    baseYInfo=input().split()
    baseYDigits=input().split()
    actualX=0
    for power in range(int(baseXInfo[0])):
        actualX+=pow(int(baseXInfo[1]),int(baseXInfo[0])-power-1)*int(baseXDigits[power])
    actualY=0
    for power in range(int(baseYInfo[0])):
        actualY+=pow(int(baseYInfo[1]),int(baseYInfo[0])-power-1)*int(baseYDigits[power])

    if(actualX==actualY):
        print("=")
    elif(actualX>actualY):
        print(">")
    else:
        print("<")
    
    
baseCompare()
