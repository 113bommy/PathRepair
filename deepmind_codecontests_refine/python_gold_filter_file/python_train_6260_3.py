import math as mt 
import sys,string
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
odd=defaultdict(int)
even=defaultdict(int)
n=I()
l=L()
x=[0,l[0]]
even[0]+=1
odd[l[0]]+=1
ans=0
for i in range(1,n):
    x.append(x[-1]^l[i])
    if(i%2==1):
        even[x[-1]]+=1
        if(even[x[-1]]==2):
            ans+=1
        elif(even[x[-1]]>2):
            ans+=even[x[-1]]-1
    else:
        odd[x[-1]]+=1
        if(odd[x[-1]]==2):
            ans+=1
        elif(odd[x[-1]]>2):
            ans+=odd[x[-1]]-1

print(ans)
