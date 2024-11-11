'''Author- Akshit Monga'''
from collections import deque
from sys import stdin,stdout
input=stdin.readline
t=1
for _ in range(t):
    n,k=map(int,input().split())
    a=[int(x) for x in input().split()]
    d={}
    arr=deque()
    for i in a:
        if not(i in d and d[i]==1):
            d[i]=1
            if len(arr)<k:
                arr.append(i)
            else:
                val=arr.pop()
                d[val]=-1
                arr.append(i)
    stdout.write(str(len(arr))+'\n')
    for i in range(len(arr)-1,-1,-1):
        stdout.write(str(arr[i])+" ")
    stdout.write('\n')