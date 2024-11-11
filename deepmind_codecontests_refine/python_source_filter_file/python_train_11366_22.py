from math import *
a,b,c=map(int,input().split())
i=0
while(True):
    if(i%2==0):
        if(gcd(a,c)>c):
            print("1")
            break
        else:
            c-=gcd(a,c)
    else:
        if(gcd(b,c)>c):
            print("0")
            break
        else:
            c-=gcd(a,c)
    i+=1