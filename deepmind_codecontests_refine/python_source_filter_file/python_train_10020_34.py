import math as mt 
import sys,string
input=sys.stdin.readline
from collections import defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())


def solve():
    n,x=M()
    c=0
    for i in range(n-1):
        a,b=M()
        if(a==x or b==x):
            c+=1
    if(n==1 or c==1):
        print("Ayush")
    else:
        if(n%2==0):
            print("Ashish")
        else:
            print("Ayush")
t=I()
for _ in range(t):
    solve()
