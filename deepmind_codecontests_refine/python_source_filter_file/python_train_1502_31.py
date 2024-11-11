import time,math,bisect,sys
sys.setrecursionlimit(100000)
from sys import stdin,stdout
from collections import deque
from fractions import Fraction
from collections import Counter
from collections import OrderedDict
pi=3.14159265358979323846264338327950
def II(): # to take integer input
    return int(stdin.readline())
def IO(): # to take string input
    return stdin.readline()
def IP(): # to take tuple as input
    return map(int,stdin.readline().split())
def L(): # to take list as input
    return list(map(int,stdin.readline().split()))
def P(x): # to print integer,list,string etc..
    return stdout.write(str(x)+"\n")
def PI(x,y): # to print tuple separatedly
    return stdout.write(str(x)+" "+str(y)+"\n")
def lcm(a,b): # to calculate lcm
    return (a*b)//gcd(a,b)
def gcd(a,b): # to calculate gcd
    if a==0:
        return b
    elif b==0:
        return a
    if a>b:
        return gcd(a%b,b)
    else:
        return gcd(a,b%a)
def readTree(): # to read tree
    v=int(input())
    adj=[set() for i in range(v+1)]
    for i in range(v-1):
        u1,u2=In()
        adj[u1].add(u2)
        adj[u2].add(u1)
    return adj,v
def bfs(adj,v): # a schema of bfs
    visited=[False]*(v+1)
    q=deque()
    while q:
        pass
def sieve():
    li=[True]*1000001
    li[0],li[1]=False,False
    for i in range(2,len(li),1):
        if li[i]==True:
            for j in range(i*i,len(li),i):
                li[j]=False
    prime=[]
    for i in range(1000001):
        if li[i]==True:
            prime.append(i)
    return prime
def setBit(n):
    count=0
    while n!=0:
        n=n&(n-1)
        count+=1
    return count
#####################################################################################
mx=10**9+7
def solve():
    s=input()
    d={}
    for ele in s:
        d[ele]=d.get(ele,0)+1
    nb,ns,nc=IP()
    pb,ps,pc=IP()
    b,s,c=d.get('B',0),d.get('S',0),d.get('C',0)
    r=II()
    low,high=0,r*2
    ans=0
    while high-low>1:
        r1=r
        mid=(low+high)//2
        b1,s1,c1=mid*b,mid*s,mid*c
        # check
        stm1,stm2,stm3=True,True,True
        if b1>nb:
            extra=b1-nb
            if pb*extra>r1:
                stm1=False
            else:
                r1=r1-pb*extra
        if s1>ns:
            extra=s1-ns
            if ps*extra>r1:
                stm2=False
            else:
                r1=r1-ps*extra
        if c1>nc:
            extra=c1-nc
            if pc*extra>r1:
                stm3=False
            else:
                r1=r1-pc*extra
        if stm1 and stm2 and stm3:
            ans=mid
            low=mid
        else:
            high=mid

    print(ans)




#t=II()
#for i in range(t):
solve()
    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #