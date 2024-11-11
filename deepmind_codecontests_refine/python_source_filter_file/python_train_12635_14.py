import math
from collections import defaultdict  as dt
from sys import stdin
inp    = lambda : stdin.readline().strip()#input()
intinp = lambda : int(inp())#int(input())
mod = int(1e9)+7
inf = float("inf")
listinp= lambda : list(map(int,stdin.readline().split()))#list(input())
mapinp = lambda : map(int,stdin.readline().split())#map(input())
def ce(a,k):
    if(a%k==0):return a//k
    else:return a//k+1

#####  Code Goes hear   #####################
for _ in range(1):
    # n,x=mapinp()
    n,k=mapinp()
    a=listinp()
    a.sort()
    i=0
    while(k>0 and i<n and a[i]<=0 ):
        a[i]*=-1
        k-=1;i+=1
    if(i>0):
        if(i>=n):
            i-=1
        elif(i<n and i<a[i-1]<=a[i]):i-=1   
    # print(a)
    if(k>0 and k%2==1):
        a[i]*=-1
    # print(a)
    print(sum(a))