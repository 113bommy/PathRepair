import sys
import math
import collections
import bisect
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
n,k=get_list()
arr=get_list()
neg=[]
pos=[]
for i in arr:
    if i>0:
        pos.append(i)
    else:
        neg.append(i)
if len(neg)>0:
    neg.sort()
    limit=min(len(neg),k)
    for i in range(limit):
        neg[i]*=-1
        k-=1
if len(pos)>0:
    pos.sort()
ans=0
if len(pos)>0 and len(neg)>0:
    if pos[0]>neg[-1]:
        if k%2==1:
            pos[0]*=-1
    else:
        if k%2==1:
            neg[-1]*=-1
    ans=sum(pos)+sum(neg)
elif len(pos)>0:
    if k % 2 == 1:
        pos[0] *= -1
    ans=sum(pos)
else:
    if k % 2 == 1:
        neg[-1] *= -1
    ans=sum(neg)
print(ans)