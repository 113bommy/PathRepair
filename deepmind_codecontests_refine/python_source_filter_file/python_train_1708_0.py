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
def recursion(balance,prev_weight,steps_done,m,ans,weights):
    if steps_done==m:
        return True
    else:
        for w in weights:
            if w==prev_weight or abs(balance)>=w:
                continue
            else:
                if (steps_done+1)%2!=0:
                    stm=recursion(balance+w,w,steps_done+1,m,ans,weights)
                else:
                    stm=recursion(w-balance,w,steps_done+1,m,ans,weights)
            if stm:
                ans[steps_done+1]=w
                return True
        else:
            return False
def solve():
    s=input()
    m=II()
    weights=[]
    for i in range(10):
        ele=s[i]
        if ele=='1':
            weights.append(i+1)
    ans=[0]*(m+1)
    stm=recursion(0,0,0,m,ans,weights)
    if stm:
        print('YES')
        print(*ans[1::])
    else:
        print('NO')

solve()

    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #