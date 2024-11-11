# Hey, there Stalker!!!
# This Code was written by:
# ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
# ▒▒╔╗╔═══╦═══╗▒▒▒╔╗▒▒▒
# ▒╔╝║║╔═╗║╔═╗╠╗▒▒║║▒▒▒
# ▒╚╗║║║║║║║║║╠╬══╣║╔╗▒
# ▒▒║║║║║║║║║║╠╣║═╣╚╝╝▒
# ▒╔╝╚╣╚═╝║╚═╝║║║═╣╔╗╗▒
# ▒╚══╩═══╩═══╣╠══╩╝╚╝▒
# ▒▒▒▒▒▒▒▒▒▒▒╔╝║▒▒▒▒▒▒▒
# ▒▒▒▒▒▒▒▒▒▒▒╚═╝▒▒▒▒▒▒▒
# ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
#from functools import reduce
from __future__ import division, print_function
mod1=int(1e9+7)
#import resource
#resource.setrlimit(resource.RLIMIT_STACK, [0x100000000, resource.RLIM_INFINITY])
#import threading
#threading.stack_size(2**26)
"""fact=[1]
#for i in range(1,100001):
#    fact.append((fact[-1]*i)%mod)
#ifact=[0]*100001
#ifact[100000]=pow(fact[100000],mod-2,mod)
#for i in range(100000,0,-1):
#    ifact[i-1]=(i*ifact[i])%mod"""
#from collections import deque, defaultdict, Counter, OrderedDict
#from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians, gcd
#from heapq import heappush, heappop, heapify, nlargest, nsmallest


# sys.setrecursionlimit(10**6) 
from sys import stdin, stdout
import bisect            #c++ upperbound
from bisect import bisect_left as bl              #c++ lowerbound bl(array,element)
from bisect import bisect_right as br             #c++ upperbound
import itertools
from collections import Counter
import collections
import math
import heapq
import re
def modinv(n,p):
    return pow(n,p-2,p)
def cin():
    return map(int,sin().split())
def ain():                           #takes array as input
    return list(map(int,sin().split()))
def sin():
    return input()
def inin():
    return int(input())
  
def Divisors(n) : 
    l = []  
    for i in range(1, int(math.sqrt(n) + 1)) :
        if (n % i == 0) : 
            if (n // i == i) : 
                l.append(i) 
            else : 
                l.append(i)
                l.append(n//i)
    return l

def most_frequent(list):
    return max(set(list), key = list.count) 
def GCD(x,y):
    while(y):
        x, y = y, x % y
    return x

def ncr(n,r,p):                                              #To use this, Uncomment 19-25 
    t=((fact[n])*((ifact[r]*ifact[n-r])%p))%p
    return t

def Convert(string): 
    li = list(string.split("")) 
    return li 

def SieveOfEratosthenes(n): 
    global prime
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    f=[]
    for p in range(2, n): 
        if prime[p]: 
            f.append(p)
    return f
prime=[]
q=[]
def dfs(n,d,v,c):
    global q
    v[n]=1
    x=d[n]
    q.append(n)
    j=c
    for i in x:
        if i not in v:
            f=dfs(i,d,v,c+1)
            j=max(j,f)
            # print(f)
    return j

#Implement heapq
#grades = [110, 25, 38, 49, 20, 95, 33, 87, 80, 90] 
#print(heapq.nlargest(3, grades)) #top 3 largest
#print(heapq.nsmallest(4, grades))
#Always make a variable of predefined function for  ex- fn=len
#n,k=map(int,input().split())
"""*******************************************************"""
def main():
    n=inin()
    v=ain()
    m=inin()
    v2=sorted(v)
    s1=[0]*n
    s2=[0]*n
    temp1=0
    temp2=0
    for i in range(n):
        s1[i]=temp1+v[i]
        s2[i]=temp2+v2[i]
        temp1=s1[i]
        temp2=s2[i]
    print(s1)
    print(s2)
    for i in range(m):
        t,l,r=map(int,input().split())
        if t==1:
            if l==1:
                print(s1[r-1])
            else:
                print(s1[r-1]-s1[l-2])
        else:
            if l==1:
                print(s2[r-1])
            else:
                print(s2[r-1]-s2[l-2])





######## Python 2 and 3 footer by Pajenegod and c1729
py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip
    range = xrange
 
import os, sys
from io import IOBase, BytesIO
 
BUFSIZE = 8192
class FastIO(BytesIO):
    newlines = 0
 
    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None
 
    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0,2), super(FastIO, self).write(s))[0])
        return s
 
    def read(self):
        while self._fill(): pass
        return super(FastIO,self).read()
 
    def readline(self):
        while self.newlines == 0:
            s = self._fill(); self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s:self.buffer.write(s.encode('ascii'))
            self.read = lambda:self.buffer.read().decode('ascii')
            self.readline = lambda:self.buffer.readline().decode('ascii')
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')
if __name__== "__main__":
    main()
#threading.Thread(target=main).start()