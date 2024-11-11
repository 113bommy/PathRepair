import sys
import math
import collections
inp= lambda : sys.stdin.readline()
m=998244353
def pre(s):
    p=1 
    while p<len(s) and s[p-1]==s[p]:
        p+=1 
    return p
def suf(s):
    p=len(s)-1
    ct=0
    while p>=0 and s[p]==s[-1]:
        p-=1
        ct+=1
    return ct

n=int(inp())
s=inp()
c1=pre(s)
c2=suf([i for i in s])
if s[0]==s[-1]:
    print((c1*c2+c1+c2+1)%m)
else:
    print((c1+c2+1)%m)
