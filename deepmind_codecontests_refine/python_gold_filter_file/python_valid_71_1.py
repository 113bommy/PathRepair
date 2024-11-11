#from math import *
from bisect import *
#from collections import *
#from random import *
#from decimal import *"""
#from heapq import *
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=inp()
fi=[int('1'*10)]
for i in range(1,10):
    for j in range(1,11):
        x=str(i)*j
        fi.append(int(x))
se=[int('1'*10),10**9]
for i in range(2,10):
    for j in range(10):
        for k1 in range(10):
            for k2 in range(2**i):
                nu=''
                z=bin(k2)[2:]
                z=z.zfill(i)
                for k3 in range(i):
                    if(z[k3]=='1'):
                        nu+=str(j)
                    else:
                        nu+=str(k1)
                se.append(int(nu))
fi.sort()
se.sort()
fk=float('inf')
while(t):
    t-=1
    n,k=ma()
    if(k==1):
        z=bisect_left(fi,n)
        print(fi[z])
        
    else:
        z=bisect_left(se,n)
        print(se[z])
