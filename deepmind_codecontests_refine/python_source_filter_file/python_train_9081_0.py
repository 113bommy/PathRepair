from bisect import *
from collections import *
from math import gcd,ceil,sqrt,floor,inf
from heapq import *
from itertools import *
from operator import add,mul,sub,xor,truediv,floordiv
from functools import *
 
#------------------------------------------------------------------------
import os
import sys
from io import BytesIO, IOBase
# region fastio
 
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
 
#------------------------------------------------------------------------
def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
#------------------------------------------------------------------------
 
from types import GeneratorType
 
 
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
 
    return wrappedfunc
 
 
farr=[1]
ifa=[]
 
def fact(x,mod=0):
    if mod:
        while x>=len(farr):
            farr.append(farr[-1]*len(farr)%mod)
    else:
        while x>=len(farr):
            farr.append(farr[-1]*len(farr))
    return farr[x]
 
def ifact(x,mod):
    global ifa
    ifa.append(pow(farr[-1],mod-2,mod))
    for i in range(x,0,-1):
        ifa.append(ifa[-1]*i%mod)
    ifa=ifa[::-1]
 
def per(i,j,mod=0):
    if i<j: return 0
    if not mod:
        return fact(i)//fact(i-j)
    return farr[i]*ifa[i-j]%mod
    
def com(i,j,mod=0):
    if i<j: return 0
    if not mod:        
        return per(i,j)//fact(j)
    return per(i,j,mod)*ifa[j]%mod
 
def catalan(n):
    return com(2*n,n)//(n+1)
 
def isprime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
 
def lowbit(n):
    return n&-n
 
def inverse(a,m):
    a%=m
    if a<=1: return a
    return ((1-inverse(m,a)*m)//a)%m
 
class BIT:
    def __init__(self,arr):
        self.arr=arr
        self.n=len(arr)-1
        
    def update(self,x,v):
        while x<=self.n:
            self.arr[x]+=v
            x+=x&-x
 
    def query(self,x):
        ans=0
        while x:
            ans+=self.arr[x]
            x&=x-1
        return ans
'''
class SMT:
    def __init__(self,arr):
        self.n=len(arr)-1
        self.arr=[0]*(self.n<<2)
        self.lazy=[0]*(self.n<<2)
        def Build(l,r,rt):
            if l==r:
                self.arr[rt]=arr[l]
                return
            m=(l+r)>>1
            Build(l,m,rt<<1)
            Build(m+1,r,rt<<1|1)
            self.pushup(rt)
        Build(1,self.n,1)
 
    def pushup(self,rt):
        self.arr[rt]=self.arr[rt<<1]+self.arr[rt<<1|1]
 
    def pushdown(self,rt,ln,rn):#lr,rn表区间数字数
        if self.lazy[rt]:
            self.lazy[rt<<1]+=self.lazy[rt]
            self.lazy[rt<<1|1]+=self.lazy[rt]
            self.arr[rt<<1]+=self.lazy[rt]*ln
            self.arr[rt<<1|1]+=self.lazy[rt]*rn
            self.lazy[rt]=0
            
    def update(self,L,R,c,l=1,r=None,rt=1):#L,R表示操作区间
        if r==None: r=self.n
        if L<=l and r<=R:
            self.arr[rt]+=c*(r-l+1)
            self.lazy[rt]+=c
            return
        m=(l+r)>>1
        self.pushdown(rt,m-l+1,r-m)
        if L<=m: self.update(L,R,c,l,m,rt<<1)
        if R>m: self.update(L,R,c,m+1,r,rt<<1|1)
        self.pushup(rt)
 
    def query(self,L,R,l=1,r=None,rt=1):
        if r==None: r=self.n
        #print(L,R,l,r,rt)
        if L<=l and R>=r:
            return self.arr[rt]
        m=(l+r)>>1
        self.pushdown(rt,m-l+1,r-m)
        ans=0
        if L<=m: ans+=self.query(L,R,l,m,rt<<1)
        if R>m: ans+=self.query(L,R,m+1,r,rt<<1|1)
        return ans
'''       
class DSU:#容量+路径压缩
    def __init__(self,n):
        self.c=[-1]*n
 
    def same(self,x,y):
        return self.find(x)==self.find(y)
 
    def find(self,x):
        if self.c[x]<0:
            return x
        self.c[x]=self.find(self.c[x])
        return self.c[x]
 
    def union(self,u,v):
        u,v=self.find(u),self.find(v)
        if u==v:
            return False
        if self.c[u]<self.c[v]:
            u,v=v,u
        self.c[u]+=self.c[v]
        self.c[v]=u
        return True
 
    def size(self,x): return -self.c[self.find(x)]
    
class UFS:#秩+路径
    def __init__(self,n):
        self.parent=[i for i in range(n)]
        self.ranks=[0]*n
 
    def find(self,x):
        if x!=self.parent[x]:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
 
    def union(self,u,v):
        pu,pv=self.find(u),self.find(v)
        if pu==pv:
            return False
        if self.ranks[pu]>=self.ranks[pv]:
            self.parent[pv]=pu
            if self.ranks[pv]==self.ranks[pu]:
                self.ranks[pu]+=1
        else:
            self.parent[pu]=pv
 
def Prime(n):
    c=0
    prime=[]
    flag=[0]*(n+1)
    
    for i in range(2,n+1):
        if not flag[i]:
            prime.append(i)
            c+=1
        for j in range(c):
            if i*prime[j]>n: break
            flag[i*prime[j]]=prime[j]
            if i%prime[j]==0: break
    #print(flag)
    return flag
 
def dij(s,graph):
    d={}
    d[s]=0
    heap=[(0,s)]
    seen=set()
    while heap:
        dis,u=heappop(heap)
        if u in seen:
            continue
        for v in graph[u]:
            if v not in d or d[v]>d[u]+graph[u][v]:
                d[v]=d[u]+graph[u][v]
                heappush(heap,(d[v],v))
    return d
 
def GP(it): return [[ch,len(list(g))] for ch,g in groupby(it)]
 
class DLN:
    def __init__(self,val):
        self.val=val
        self.pre=None
        self.next=None

def nb(i,j):
    for ni,nj in [[i+1,j],[i-1,j],[i,j-1],[i,j+1]]:
        if 0<=ni<n and 0<=nj<m:
            yield ni,nj
            
@bootstrap
def gdfs(r,p):
    if len(g[r])==1 and p!=-1:
        yield None
    for ch in g[r]:
        if ch!=p:
            yield gdfs(ch,r)
    yield None





t=1
for i in range(t):
    n=N()
    a=RLL()
    b=RLL()
    if n==1:
        if a==b:
            print('small')
            print('0')
            print()
        else:
            print('impossible')
    elif n==2:
        if a==b:
            print('small')
            print('0')
            print()
        elif a==b[::-1]:
            print('small')
            print('1')
            print('r')
        else:
            x,y=min(a),max(a)
            ans=''
            p,q=min(b),max(b)
            c=0
            while p>x:
                c+=(q//p)
                if c<=2*10**5:
                    ans+='p'*(q//p)
                p,q=q%p,p   
                ans+='r'
            #print(x,y,p,q,ans)
            if p<x:
                print('impossible')
            else:
                if q<y or (q-y)%x:
                    print('impossible')
                else:
                    c+=(q-y)//x
                    if c>2*10**5:
                        print('big')
                        print(c)
                    else:
                        ans+='p'*((q-y)//x)
                        print('small')
                        res=''
                        if a==[y,x]:
                            res+='r'
                        res+=ans[::-1]
                        if b==[q,p]:
                            res+='r'
                        print(len(res))
                        print(res)            
    else:
        ans=[]
        c=0
        f=True
        ar=a[::-1]
        while b!=a and b!=ar:
            if b[1]<b[0]:
                b.reverse()
                ans.append('R')
            b=[b[i]-b[i-1] if i else b[i] for i in range(n)]
            if min(b)<=0:
                f=False
                break
            ans.append('P')
            c+=1
        if not f:
            print('impossible')
        else:
            if c>2*10**5:
                print('big')
                print(c)
            else:
                if b==ar:
                    ans.append('R')
                ans.reverse()
                print('small')
                print(len(ans))
                print(''.join(ans))
 


 
 

''' 
sys.setrecursionlimit(200000)
import threading
threading.stack_size(10**8)
t=threading.Thread(target=main)
t.start()
t.join()
'''

''' 
sys.setrecursionlimit(200000)
import threading
threading.stack_size(10**8)
t=threading.Thread(target=main)
t.start()
t.join()
'''
