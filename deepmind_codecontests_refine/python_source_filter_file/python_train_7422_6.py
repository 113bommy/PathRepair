#THIS CODE IS MADE BY "harshest2019"
from sys import *
from math import ceil
ws=lambda:map(int,stdin.readline().strip().split())
li=lambda:list(map(int,stdin.readline().strip().split()))
mod=1000000007
def ncr(n, r, p): 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p 
    return (num * pow(den, p - 2, p)) % p
 
def gcd(a,b):
    if (b == 0): 
         return a 
    return gcd(b, a%b)
def prod(l):
    ans=1
    for i in range(len(l)):
        ans=ans*l[i]
    return ans
def sortindex(l,a):
    c=[]
    if(a==-1):
        rev=True
    else:
        rev=False
    for i in range(len(l)):
        c.append([l[i],i])
    x=sorted(c,reverse=rev)
    print(x)
    c=[]
    for i in range(len(l)):
        c.append(x[i][1])
    return c

#CODE STARTS HERE

for _ in range(int(input())):
    n=int(input())
    s=stdin.readline().strip()
    l=[1]*n
    for i in range(len(s)):
        if(s[i]=='L'):
            l[i]=-1
        else:
            l[i]=1
    forw=[(0,0)]*(n+1)
    back=[(0,0)]*(n+1)
    count=0
    
    for i in range(len(s)+1):
        flag=0
        if(i==0):
            back[i]=(0,0)
        else:
            if(l[i-1]==-1):
                back[i]=(1+back[i-1][1],0)
            else:
                back[i]=(0,1+back[i-1][0])
    for i in range(len(s)+1):
        flag=0
        if(i==0):
            forw[-1]=(0,0)
        else:
            if(l[-i]==1):
                forw[-1-i]=(1+forw[-i][1],0)
            else:
                forw[-1-i]=(0,1+forw[-1][0])
    ans=[]
    for i in range(n+1):
        ans.append(back[i][0]+forw[i][0]+1)
    print(*ans)