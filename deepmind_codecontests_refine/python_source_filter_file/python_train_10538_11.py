import math,sys
from collections import Counter, defaultdict, deque
from sys import stdin, stdout
input = stdin.readline
li = lambda:list(map(int,input().split()))

def case():
    n,m,p=li()
    a=li()
    b=li()
    x,y=-1,-1
    for i in range(n):
        if(a[i]%p!=0):
            x=i
            break
    for i in range(n):
        if(b[i]%m!=0):
            y=i
            break
    print(x+y)


for _ in range(1):
    case()