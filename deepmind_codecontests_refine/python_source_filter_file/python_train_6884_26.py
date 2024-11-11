import math
from decimal import *
import random
mod = int(1e9)+7

s = list(input())
n = len(s)
p1,p2 = -1,-1
for i in range(n):
    if(s[i]=='['and p1==-1):
        p1 = i
    if(s[i]==']'):
        p2 = i+1
if(p1 < p2-1 and p1!= -1 and p2!=-1 and p2-p1-3>=0):
    s = s[p1:p2]
    n= len(s)
    ans = int(n)
    p1, p2 = -1,-1
    for i in range(n):
        if(s[i]==':' and p1==-1):
            p1 = i
        if(s[i]==':'):
            p2 = i+1
    if(p1<p2 and p1!=-1 and p2!=-1 and p2-p1-3>=0):
        s=s[p1:p2]
        n =len(s)
        ans -= (ans-n)
        cnt = 0
        for i in range(1, n-1):
            if(s[i]!= '|'):
                cnt+=1
        ans-=cnt
        print(ans+2)
    else:
        print(-1)
else:
    print(-1)
