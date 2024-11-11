from bisect import bisect_left as bl, bisect_right as br, insort
import sys
import heapq
from math import *
from collections import defaultdict as dd, deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())
#sys.setrecursionlimit(100000)

def conv(x,k):
    s=''
    while x:
        t=x%k
        if t>1:
            s=''
            break
        else:
            s= str(t)+ s
        x//=k
    return s

for i in range(int(data())):
    n,k=mdata()
    A=list(mdata())
    t=1
    flag=True
    l=[0]*60
    for i in A:
        a=conv(i,k)
        if a=='':
            flag=False
            break
        for i in range(len(a)):
            if a[i]=='1':
                l[len(a)-i-1]+=1
    for i in l:
        if i>1:
            flag=False
            break
    if flag==True:
        print("YES")
    else:
        print("NO")