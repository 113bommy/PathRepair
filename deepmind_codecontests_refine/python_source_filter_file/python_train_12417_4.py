#from math import *
from bisect import *
from collections import *
from random import *
from decimal import *
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
p=10**9 + 7
s=st()
pre=[int(s[0])]
for i in range(1,len(s)):
    re=pre[-1]*10
    re%=p
    re+=int(s[i])
    re%=p
    pre.append(re)
suf=[int(s[-1])]
for i in range(len(s)-1):
    re=int(s[len(s)-i-2])*int(pow(10,i+1,p))
    re%=p
    re+=suf[-1]
    re%=p
    suf.append(re)
sufarr=[suf[0]]
for i in range(1,len(s)):
    sufarr.append((sufarr[-1]+suf[i])%p)
pre.pop()
suf.pop()
sufarr.pop()
n=len(pre)
inv=int(pow(9,p-2,p))
res=sum(pre)
res%=p
res+=sum(suf)
res%=p
#print(pre,suf,sufarr,res)
for i in range(n-1):
    gp=10
    re=pow(10,n-i-1,p)-1
    gp=(gp*re)%p
    gp=gp*inv
    gp=gp%p
    print(gp)
    ff=(pre[i]*gp)%p
    ff+=sufarr[n-i-2]
    res+=ff
    res%=p
print(res)
    

    

