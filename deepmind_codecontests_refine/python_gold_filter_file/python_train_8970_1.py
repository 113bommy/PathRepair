#This code is contributed by Siddharth
from bisect import *
from math import *
from collections import *
from heapq import *
from itertools import *
inf=10**18
mod=10**9+7





# ==========================================> Code Starts Here <=====================================================================


n,k=map(int,input().split())
a=list(map(int,input().split()))
if k==1:
    print(0)
    exit()
a.sort()

sett=set([])
for i in range(n):
    temp=a[i]
    while temp:
        sett.add(temp)
        temp//=2
sett.add(0)
minn_ans=inf
for i in sett:
    arr=[]
    for j in range(n):
        temp=a[j]
        cnt=0
        while temp!=i:
            if temp==0:
                break
            cnt+=1
            temp//=2
        if temp==i:
            arr.append(cnt)
    arr.sort()
    if len(arr)>=k:
        minn_ans=min(minn_ans,sum(arr[0:k]))
print(minn_ans)






















