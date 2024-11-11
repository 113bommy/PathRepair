import time,math,bisect
from sys import stdin,stdout
from collections import deque
from fractions import Fraction
from collections import Counter
pi=3.14159265358979323846264338327950
def Ii():
    return int(stdin.readline())
def Is():
    return stdin.readline()
def In():
    return map(int,stdin.readline().split())
def L():
    return list(map(int,stdin.readline().split()))
def P(x):
    return stdout.write(str(x)+"\n")
def Pi(x,y):
    return stdout.write(str(x)+" "+str(y)+"\n")
def lcm(a,b):
    return (a*b)//gcd(a,b)
def gcd(a,b):
    if a==0:
        return b
    elif b==0:
        return a
    if a>b:
        return gcd(a%b,b)
    else:
        return gcd(a,b%a)
def readTree():
    v=int(input())
    adj=[set() for i in range(v+1)]
    for i in range(v-1):
        u1,u2=In()
        adj[u1].add(u2)
        adj[u2].add(u1)
    return adj,v
def bfs(adj,v):
    visited=[False]*(v+1)
    q=deque()
    while q:
        pass
#####################################################################################
def solve():
    s=input()
    n=len(s)
    new=s[0]
    d={}
    pcons,cons,val=False,False,1
    for i in range(1,n):
        if s[i]==s[i-1]:
            if pcons==False:
                cons=True
                val+=1
                if val!=3:
                    new+=s[i]
                else:
                    val=2
            else:
                cons=True
        else:
            val=1
            new+=s[i]
            cons=False
        if i<(n-1) and s[i]!=s[i+1]:
            if cons==True:
                pcons=True
            else:
                pcons=False
    print(new)



solve()