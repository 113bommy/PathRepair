import math,sys
from sys import stdin, stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def case():
    n=I()
    a=[]
    for i in range(n):
        a.append(float(input())) 
    b=[] 
    s=0 
    for i in range(n):
        b.append(int(a[i]))
        s+=b[i] 
    i=0 
    for i in range(n):
        if(s==0):
            break 
        if(s>0):
            if(a[i]>b[i]):
                continue 
            else:
                b[i]-=1
                s-=1
        else:
            if(a[i]<b[i]):
                continue 
            else:
                b[i]+=1
                s+=1 
    for i in b:
        print(i)


for _ in range(1):
    case()