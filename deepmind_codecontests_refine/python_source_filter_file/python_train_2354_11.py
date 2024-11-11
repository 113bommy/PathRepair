import sys
numberOfIntegers = sys.stdin.readline()
Integers = sys.stdin.readline()

number = int( numberOfIntegers )
print (number)
eachInteger = Integers.split()
#print (3 % 2)
stillOkay = True
for i in range( 0 , number ):
    print(i)

    #print ( eachInteger[i] )
    eachInteger[i] = int( eachInteger[i] )
    if eachInteger[i] % 2 == 0:
        pass
    elif eachInteger[i] % 2 == 1:
        stillOkay = False
#print (eachInteger[0])
#print (stillOkay)
if stillOkay == True:
    print ( "Second" )
else :
    print ( "First" )
        

#range does the minus one by itself  
