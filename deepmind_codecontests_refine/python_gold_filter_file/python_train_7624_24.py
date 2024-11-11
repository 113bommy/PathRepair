import math as mt 
import sys,string
input=sys.stdin.readline
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
n=I()
for _ in range(n):
    a,b=M()
    p=max(a,b)
    k=min(a,b)
    print(max(p,2*k)**2)
    
