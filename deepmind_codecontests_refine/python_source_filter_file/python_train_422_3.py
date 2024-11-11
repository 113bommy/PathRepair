from collections import *
import sys
input=sys.stdin.readline
n,q=map(int,input().split())
a=list(map(int,input().split()))
f=Counter(a)
d=[]
for i in f.keys():
    d.append([i,f[i]])
d.sort(reverse=True)
l1=len(d)
for i in range(q):
    x=int(input())
    s=0
    l=0
    while(x>0 and l<len(d)):
        q=x//d[l][0]
        q=min(d[l][1],q)
        if(q!=0):
            s+=1
            x-=q*d[l][0]
        l+=1
    if(x==0):
        print(s)
    else:
        print(-1)
            
