n = int(input())
if(n%2 == 0):
    for i in range(int(n/2)):
        print("WB"*int(n/2))
        print("BW"*int(n/2))
else:
    for i in range(5):
        if (i%2 == 0):
            print("B"+"WB"*int(n/2))
        else:
            print("WB"*int(n/2) + "W")