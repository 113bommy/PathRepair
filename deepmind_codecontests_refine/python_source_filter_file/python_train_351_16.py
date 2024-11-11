import sys
import math as mt
input=sys.stdin.buffer.readline  
#t=int(input())
t=1
for __ in range(t):
    n=int(input())
    #n,h=map(int,input().split())
    l=list(map(int,input().split()))
    maxi=max(l[:])
    a1=0
    for i in range(n):
        a1+=(maxi-l[i])
    print(maxi+mt.ceil((maxi+n-a1-1)/(n-1))-1)    
            