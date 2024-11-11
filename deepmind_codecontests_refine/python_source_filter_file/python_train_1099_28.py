import math
#print(1378**14)
#Problem 1
n=int(input())
#print(1378**n)
if n==0:
    print(1)
if n!=1:
    for i in range(1, 5):
        if (n+4-i)%4==0:
            if i==1:
                print(8)
            if i==2:
                print(4)
            if i==3:
                print(2)
            if i==4:
                print(6)
            break

