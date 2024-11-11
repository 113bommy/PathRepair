from sys import stdin,stdout
from math import gcd
nmbr=lambda:int(stdin.readline())
lst = lambda: list(map(int,input().split()))
for _ in range(1):#nmbr():
    n,m=lst()
    a=lst()
    b=lst()
    if m>n:print('0/1')
    elif n>m:print('-Infinity' if a[0]*b[0]<0 else 'Infinity')
    else:
        h=gcd(a[0],b[0])
        num=a[0]//h
        den=b[0]//h
        if den*num<0:
            den=abs(den)
            num=-1*abs(num)
        else:
            den = abs(den)
            num = abs(num)
        print(num,'/',den//h,sep='')
