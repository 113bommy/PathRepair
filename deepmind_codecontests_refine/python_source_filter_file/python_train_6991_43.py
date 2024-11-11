import math
x,y,z=map(int,input().split())
xx=x-y 
if abs(xx)>z:
    if xx<0:
        print("-")
    elif xx==0:
        print(0)
    else:
        print('+')
else:
    print('?')