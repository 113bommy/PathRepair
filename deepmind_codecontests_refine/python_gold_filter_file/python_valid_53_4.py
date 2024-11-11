'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline
t = int(input())
for _ in range(t):
    n,p=map(int,input().split())
    a=[int(x) for x in input().split()]
    vals=sorted(a)
    d={}
    for i in range(n):
        d[vals[i]]=i
    # print(d)
    k=0
    for i in range(n-1):
        x=d[a[i+1]]
        y=d[a[i]]
        if x!=y+1:
            k+=1
    k+=1
    if k<=p:
        print("yes")
    else:
        print("no")