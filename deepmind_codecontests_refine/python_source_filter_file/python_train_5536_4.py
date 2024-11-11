
from collections import deque, defaultdict
from math import sqrt, ceil,factorial,floor
import sys
import copy
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()
maxn=(10**5)+1


n=int(input())
a=get_array()
q=int(input())
mya=[-1]*n
c=[]
for i in range(q):
    b=get_array()
    if b[0]==1:
        mya[b[1]-1]=i
    c.append(b)

myb=[-1]*(len(c))
for i in range(len(c)-1,-1,-1):
    if c[i][0]==2:
        myb[i]=max(myb[i],c[i][1])
    if i+1<=len(c)-1:
            myb[i]=max(myb[i+1],myb[i])

ans=[]

for i in range(n):
    if mya[i]==-1:
        ans.append(max(a[i],myb[0]))
    else:
        ind=mya[i]
        my=c[ind][2]
        ans.append(max(my,myb[i]))
print(*ans)