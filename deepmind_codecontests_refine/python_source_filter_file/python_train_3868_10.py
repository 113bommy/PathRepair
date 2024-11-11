#31938917
from collections import defaultdict as DD
from bisect import bisect_left as BL
from bisect import bisect_right as BR
from itertools import combinations as IC
from itertools import permutations as IP
from random import randint as RI
import sys
MOD=pow(10,9)+7

def IN(f=0):
    if f==0:
        return ( [int(i) for i in sys.stdin.readline().split()] )
    else:
        return ( int(sys.stdin.readline()) )

def fnx(n):
    f=list(str(n))
    f=[int(u) for u in f]
    r=1
    for i in f:
        r*=i
    return(r)
    
"""
def fnx(n):
    f=list(str(n))
    f=[int(u) for u in f]
    t=-1
    fla=0
    for i in range(len(f)):
        if f[i]==0 and t==-1:
            t=i
        if f[i]==0:
            fla=1
    w=f[:t-1]+ [f[t-1]-1] + [9]*(len(f)-t)
    while(w[0]==0):
        del w[0]

    r=1
    for i in w:
        r*=i
    return(r)

n=IN(1)
if len(str(n))==1:
    print(n)
    
elif n%10==0:
    m=n-1
    f=list(str(m))
    f=[int(u) for u in f]
    ans=1
    for i in f:
        ans*=i
    gf=len(list(str(n)))
    yt=9**(gf-1)
    print(max(ans,yt))
    
else:
    rr=n%10
    m=n-rr-1
    f=list(str(m))
    f=[int(u) for u in f]
    ans1=1
    for i in f:
        ans1*=i

    df=fnx(m)
    
    
    m=n-1
    f=list(str(m))
    f=[int(u) for u in f]
    ans2=1
    for i in f:
        ans2*=i
    #print(max(ans1,ans2))
    gf=len(list(str(n)))
    yt=9**(gf-1)
    print(max(ans1,yt,ans2,df))
"""
n=IN(1)
if len(str(n))==1:
    print(n)
else:
    f=list(str(n))
    f=[int(u) for u in f]
    k=len(f)
    ans=[]
    for i in range(k):
        ans.append( fnx(n*pow(10,i)-1) )
        n=n//10
    print(max(max(ans),fnx(n)))
        



