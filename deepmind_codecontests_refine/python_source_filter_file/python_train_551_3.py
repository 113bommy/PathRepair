from math import *
from collections import defaultdict as dt
from sys import *
setrecursionlimit(100000)
inp = lambda : stdin.readline().strip()
I   = lambda : int(inp())
M   = lambda : map(int,inp().split())
L   = lambda : list(M())
mod = 1000000007
inf = 100000000000000000000
ss  = "abcdefghijklmnopqrstuvwxyz"
############## All the best start coding #############

def solve():
    n=I()
    a1=[]
    a=0
    for _ in range(n):
        q,w=M()
        a+=(q<<1)
        a1.append([q,w])
    a1.sort(key = lambda x: x[1])
    a1.reverse()
    i,j,c=0,n-1,0
    while i<=j:
        k=a1[j][1]
        if((i^j)==0):
            a-=max(-inf,a1[i][0]-max(-inf,a1[i][1]-c))
            break
        elif(c>=k):
            a-=a1[j][0]
            j=j-1
            c+=a1[j+1][0]
        elif(c+a1[i][0]<=a1[j][1]):
            c+=a1[i][0]
            i=i+1
            a1[i-1][0]=0
        else:
            q=a1[j][1]-c
            c+=q
            c+=a1[j][0]
            a1[i][0]-=q
            j=j-1
            a-=a1[j+1][0]
    print(a)    
    
##################### Submit now #####################

tt=1
#tt=I()
for _ in range(tt):
    solve()