
from decimal import *
a=int(input())
b=[]
for i in range(a):
    b.append(int(input()))
    
for i in b:
    if(i<2):
        print('Y',i,i)
        continue
    x=2.0
    y=1.0
    z=0
    while(abs(x+(i-x)-x*(i-x))>=pow(10,-6) and z<20):
        while((i-x)*x>i):
            x=round(x-y,z)
        x=round(x+y,z)
        y/=10
        z+=1
    if(z<20):
        print('Y',i-x,x)
    else:
        print('N')
