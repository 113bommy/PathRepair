import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod = int(1e9)+7



for t in range(int(data())):
    n,x,y=mdata()
    a=mdata()
    d=dd(list)
    for i in range(n):
        d[a[i]].append(i)
    q=[]
    for i in d.keys():
        heappush(q,[-len(d[i]),i])
    ind=1
    while d[ind]:
        ind+=1
    ans=[ind]*n
    for i in range(x):
        j,k=heappop(q)
        i=d[k].pop()
        ans[i]=a[i]
        heappush(q, [-len(d[k]), k])
    l1=[]
    while q:
        j, k = heappop(q)
        l1+=d[k]
    ind=0
    flag=True
    y-=x
    n-=x
    l1=l1[::-1]
    while ind<y:
        if a[l1[ind]]==a[l1[(n//2+ind)%n]]:
            flag=False
            break
        ans[l1[ind]]=a[l1[(n//2+ind)%n]]
        y-=1
        if ind>=y:
            break
        ans[ind-n//2]=a[l1[ind]]
        ind+=1
    if flag==True:
        out("YES")
        outl(ans)
    else:
        out("NO")





