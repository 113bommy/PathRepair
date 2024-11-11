from math import *
a=input()
n=int(a,2)
if(n==0):
    print(0)
    exit(0)
x=floor(log(n,4))
if(pow(x,4)==n or pow(x,4)==n+1):
    x-=1
print(x+1)
