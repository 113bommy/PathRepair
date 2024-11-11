import math,sys
from sys import stdin, stdout
from collections import Counter, defaultdict, deque
input = stdin.readline
I = lambda:int(input())
li = lambda:list(map(int,input().split()))


def ham(mid):
    br=(b*mid-nb)*pb 
    sr=(s*mid-ns)*ps
    cr=(c*mid-nc)*pc
    if(br<0):
        br=0
    if(sr<0):
        sr=0 
    if(cr<0):
        sr=0
    if(br+sr+cr<=money):
        return(True)
    return(False)
    


a=input().strip()
nb,ns,nc=li()
pb,ps,pc=li()
b,s,c=a.count('B'),a.count('S'),a.count('C')
money=I()
l,r=0,10**12
ans=0
while(l<=r):
    #print(l,r)
    mid=(l+r)//2
    if(ham(mid)):
        ans=mid
        l=mid+1
    else:
        r=mid-1
print(ans)