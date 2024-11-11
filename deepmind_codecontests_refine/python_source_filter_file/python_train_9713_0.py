import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
 
from collections import deque
for i in range(int(input())):
    n=int(input())
    alist=list(map(int,input().split()))
    alist.sort()
    maxN=alist[-1]+1
    anslist=[0]*maxN
    blist=[0]*maxN
    maxans=0
    for i,val in enumerate(alist):blist[val]+=1
    for i in range(1,maxN):
        count=anslist[i]+blist[i]
        maxans=max(count,maxans)
        for j in range(2*val,maxN,val):
            anslist[j]=max(count,anslist[j])
    print(n-maxans)