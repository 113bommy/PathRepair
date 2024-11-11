import sys
import itertools as it
import math as mt
import bisect as bi
import collections as cc
import itertools as it
input=sys.stdin.readline
I=lambda:list(map(int,input().split()))
n,q=I()
ar=list(range(1,n+1))
pref=[0]
for i in range(n):
    pref.append(pref[-1]+ar[i])
arr=ar[-15::]
clen=len(arr)
nxt=0
fact=[1,1]
for i in range(2,20):
    fact.append(fact[-1]*i)
def ch(n):
    temp=[i for i in arr]
    re=[]
    for i in range(clen,0,-1):
        cur=n//fact[i-1]
        n-=(cur*(fact[i-1]))
        re.append(temp.pop(cur))
    return re
for tc in range(q):
    now=I()
    if now[0]==2:
        nxt+=now[1]
        continue
    left,right=now[1],now[2]
    if right<=n-clen:
        print(pref[right]-pref[left-1])
        continue
    elif left<=n-clen:
        ans=pref[-clen-1]-pref[left-1]
        left=0
        right=n-clen+1
    else:
        ans=0
        left-=n-clen+1
        right-=n-clen+1
    cur=ch(nxt)
    print(ans+sum(cur[left:right+1]))