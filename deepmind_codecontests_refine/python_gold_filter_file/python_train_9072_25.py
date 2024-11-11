from math import *
n = int(input())
if n%2==0:
    b = (ceil(n/2))+1
else:
    b = ceil(n/2)
if n == 1:
    print(1)
else:
    print(b)
x = 1
c = 0
if n == 1:
    print("1 1")
else:
    for y in range(1,b+1):
        if c == n:
            break
        for z in range(1,b+1):
            if x == 1:
                print(z,y)
                x += 1
                c += 1
            elif abs(y-1)+abs(z-1) >= x-1:
                print(z,y)
                c += 1
                x += 1

