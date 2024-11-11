###### Importing Libraries ######
import math
import operator as op
from functools import reduce
from fractions import Fraction as frac
#################################
##### User defined function #####

############ NCR ###############
def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom
    



############ DSU ###############
global par
# par=[-1 for i in range(100001)]
# t=rd(1)
def find(u):
    if(par[u]<0):
        return u
    else:
        return find(par[u])
def uni(x,y):
    u=find(x)
    v=find(y)
    if u==v:
        return
    if(par[u]<par[v]):
        par[u]+=par[v]
        par[v]=u
    else:    
        par[v]+=par[u]
        par[u]=v
################################        
        
############ READ ###############
def rd(p):
    if(p==0):
        return input()
    if(p==1):
        return int(input())
    if(p==2):
        return map(int,input().split())
    if(p==3):
        return list(map(int,input().split()))
    if(p==4):
        return map(str,input().split())
t=1
for term in range(1,t+1):
    n=int(input())
    s=list(input())
    ans=[]
    for i in range(n):
        if(s[i]=='0'or s[i]=='1'):
            continue
        if(s[i]=='2' or s[i]=='5' or s[i]=='7' or s[i]=='3'):
            ans.append(s[i])
        elif(s[i]=='4'):
            ans=ans+['3','2','2']
        elif(s[i]=='8'):
            ans=ans+['7','2','2']
        elif(s[i]=='9'):
            ans+=['7','3','3','2']
        else:
            ans+=['5','3']
    ans.sort(reverse=True)
    for i in range(len(ans)):
        print(ans[i],end="")
    