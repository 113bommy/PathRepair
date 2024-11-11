import math,sys
from sys import stdin,stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))

def solve():
    n,m=li()
    a=li()
    b=li()
    c=[]
    for i in range(n):
        p=a[i]
        q=[]
        for j in range(m):
            p=min(p,a[i]&b[j])
            q.append(bin(a[i]&b[j]))
        #print(*q,p)
        c.append(p)
    p=max(c)
    for i in range(n):
        temp=10000000
        for k in range(m):
            h=k+1
            q=p|(b[k]&a[i])
            for j in range(1,m):
                h%=m
                q=min(q,p|(b[h]&a[i]))
                h+=1
                h%=m
            temp=min(temp,q)
        p=q
            
    print(p)
for _ in range(1):
    solve()