import math
s=int(input())
e='abcd'
if(s<=4):
    print(e[0:s])
else:
    f=math.floor((s)/4)
    e=e*(f)
    if(s%4!=0):
        print(e+e[0:(s%4)])
    else:
        print(e)