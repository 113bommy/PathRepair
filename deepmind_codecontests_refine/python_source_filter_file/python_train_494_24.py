from math import gcd
import sys
input = sys.stdin.readline
n=int(input())
dic={}
z=0
mod=10**9+7
for i in range(n):
    a,b=map(int,input().split())
    if a==b==0:
        z+=1
        continue
    k=gcd(a,b)
    a//=k
    b//=k
    if b<0:
        a=-a
        b=-b
    if b==0 and a<0:
        a=-a
    if a<=0:
        a,b=b,-a
        if (a,b) in dic:
            dic[(a,b)][0]+=1
        else:
            dic[(a,b)]=[1,0]
    else:
        if (a,b) in dic:
            dic[(a,b)][1]+=1
        else:
            dic[(a,b)]=[0,1]
ans=1
for x in dic:
    v=dic[x]
    s = v[0]
    t = v[1]
    ans*=pow(2,s,mod)+pow(2,t,mod)-1
    ans%=mod
print(z-1+ans)