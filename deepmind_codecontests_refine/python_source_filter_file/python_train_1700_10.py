#######puzzleVerma#######


import sys
import math
from typing import DefaultDict
mod = 10**9+7


LI=lambda:[int(k) for k in input().split()]
input = lambda: sys.stdin.readline().rstrip()
IN=lambda:int(input())
S=lambda:input()
r=range


for tt in r(IN()):
    ll=S()
    n,k=LI()
    a=LI()
    t=LI()
    d=DefaultDict(int)
    for i in range(k):
        d[a[i]-1]=t[i]
    a.sort()
    ans=[10**9]*n
    temp=10**9
    for i in range(a[0]-1,n):
        if d[i]>0:
            temp=min(temp,d[i])
        ans[i]=temp
        temp+=1
        
    temp=10**9
    for i in range(a[-1]-1,-1,-1):
        if d[i]>0:
            temp=min(temp,d[i])
        ans[i]=min(ans[i],temp)
        temp+=1

    print(*ans)




