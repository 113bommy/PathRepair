import time,math,bisect,sys,heapq
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
    return stdout.write(str(x))
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
    n,k=IP()
    if k==0:
        print(0)
        for i in range(n):
            print('0'*n)
    else:
        li=[['0' for j in range(n)] for i in range(n)]
        if k<=n:
            for i in range(k):
                li[i][i]='1'
            if k==n:
                print(0)
            else:
                print(2)
            for ele in li:
                print("".join(ele))
        else:
            for i in range(n):
                li[i][i]='1'
            k-=n
            i=1
            j=1
            turn=0
            while k>0:
                if turn%2!=0:
                    x,y=i,0
                    while k>0 and x<n and y<n:
                        li[x][y]='1'
                        k-=1
                        x+=1
                        y+=1
                    i+=1
                else:
                    x,y=0,j
                    while k>0 and x<n and y<n:
                        li[x][y]='1'
                        k-=1
                        x+=1
                        y+=1
                    j+=1
                turn+=1
            mxr,mnr,mxc,mnc=-1*sys.maxsize,sys.maxsize,-1*sys.maxsize,sys.maxsize
            for ele in li:
                c=ele.count('1')
                mxr=max(mxr,c)
                mnr=min(mnr,c)
            for i in range(n):
                c=0
                for j in range(n):
                    if li[j][i]=='1':
                        c+=1
                mxc=max(mxc,c)
                mnc=min(mnc,c)
            print((mxr-mnr)**2+(mxc-mnc)**2)
            for ele in li:
                print("".join(ele))






t=II()
for i in range(t):
    solve()

    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #