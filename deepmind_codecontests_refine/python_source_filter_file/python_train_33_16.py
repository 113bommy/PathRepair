from math import *
a=[int(i) for i in input().split()]
if(a[0]==0 and  a[1]==0 and a[2]==0):
    print("-1")
    exit()
if(a[0]==0 and a[1]!=0):
    print("1")
    print((-a[2])/a[1])
elif(a[0]==0 and a[1]==0):
    print("0")
    exit()
else:
    if((a[1]*a[1]-4*a[0]*a[2])<0):
        print("0")
    elif((a[1]*a[1]-4*a[0]*a[2])==0):
        print("1")
        print((-a[1])/(2*a[0]))
    else:
        print(2)
        print(min((-a[1]+sqrt(a[1]*a[1]-4*a[0]*a[2]))/2*a[0],(-a[1]-sqrt(a[1]*a[1]-4*a[0]*a[2]))/2*a[0]))
        print(max((-a[1]+sqrt(a[1]*a[1]-4*a[0]*a[2]))/2*a[0],(-a[1]-sqrt(a[1]*a[1]-4*a[0]*a[2]))/2*a[0]))

