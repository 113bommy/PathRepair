import sys,os
from io import BytesIO,IOBase
# from functools import lru_cache
mod = 10**9+7; Mod = 998244353; INF = float('inf')
# input = lambda: sys.stdin.readline().rstrip("\r\n")
# inp = lambda: list(map(int,sys.stdin.readline().rstrip("\r\n").split()))
#______________________________________________________________________________________________________
# region fastio
# ''' 
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
# endregion'''
#______________________________________________________________________________________________________
input = lambda: sys.stdin.readline().rstrip("\r\n")
inp = lambda: list(map(int,sys.stdin.readline().rstrip("\r\n").split()))
# ______________________________________________________________________________________________________
# from math import *
# from bisect import *
# from heapq import *
# from collections import defaultdict as dd
# from collections import OrderedDict as odict
# from collections import Counter as cc
# from collections import deque
# from itertools import groupby
# from itertools import combinations
# sys.setrecursionlimit(100_100) #this is must for dfs
# ______________________________________________________________________________________________________
# segment tree for range minimum query and update 0 indexing
# init = float('inf')
# st = [init for i in range(4*len(a))]
# def build(a,ind,start,end):
#     if start == end:
#         st[ind] = a[start]
#     else:
#         mid = (start+end)//2
#         build(a,2*ind+1,start,mid)
#         build(a,2*ind+2,mid+1,end)
#         st[ind] = min(st[2*ind+1],st[2*ind+2])
# build(a,0,0,n-1)
# def query(ind,l,r,start,end):
#     if start>r or end<l:
#         return init
#     if l<=start<=end<=r:
#         return st[ind]
#     mid = (start+end)//2
#     return min(query(2*ind+1,l,r,start,mid),query(2*ind+2,l,r,mid+1,end))
# def update(ind,val,stind,start,end):
#   if start<=ind<=end:
#       if start==end:
#           st[stind] = a[start] = val
#       else:
#           mid = (start+end)//2
#           update(ind,val,2*stind+1,start,mid)
#           update(ind,val,2*stind+2,mid+1,end)
#           st[stind] = min(st[left],st[right])
# ______________________________________________________________________________________________________
# Checking prime in O(root(N))
# def isprime(n):
#     if (n % 2 == 0 and n > 2) or n == 1: return 0
#     else:
#         s = int(n**(0.5)) + 1
#         for i in range(3, s, 2):
#             if n % i == 0:
#                 return 0
#         return 1
# def lcm(a,b):
#   return (a*b)//gcd(a,b)
# returning factors in O(root(N))
# def factors(n):
#     fact = []
#     N = int(n**0.5)+1
#     for i in range(1,N):
#         if (n%i==0):
#             fact.append(i)
#             if (i!=n//i):
#                 fact.append(n//i)
#     return fact
# ______________________________________________________________________________________________________
# Merge sort for inversion count
# def mergeSort(left,right,arr,temp):
#     inv_cnt = 0
#     if left<right:
#         mid = (left+right)//2
#         inv1 = mergeSort(left,mid,arr,temp)
#         inv2 = mergeSort(mid+1,right,arr,temp)
#         inv3 = merge(left,right,mid,arr,temp)
#         inv_cnt = inv1+inv3+inv2
#     return inv_cnt
# def merge(left,right,mid,arr,temp):
#     i = left
#     j = mid+1
#     k = left
#     inv = 0
#     while(i<=mid and j<=right):
#         if(arr[i]<=arr[j]):
#             temp[k] = arr[i]
#             i+=1
#         else:
#             temp[k] = arr[j]
#             inv+=(mid+1-i)
#             j+=1
#         k+=1
#     while(i<=mid):
#         temp[k]=arr[i]
#         i+=1
#         k+=1
#     while(j<=right):
#         temp[k]=arr[j]
#         j+=1
#         k+=1
#     for k in range(left,right+1):
#         arr[k] = temp[k]
#     return inv
# ______________________________________________________________________________________________________
# nCr under mod
# def C(n,r,mod = 10**9+7):
#   if r>n: return 0
#   if r>n-r: r = n-r
#   num = den = 1
#   for i in range(r):
#       num = (num*(n-i))%mod
#       den = (den*(i+1))%mod
#   return (num*pow(den,mod-2,mod))%mod
# def C(n,r):
#   if r>n:
#       return 0
#   if r>n-r:
#       r = n-r
#   ans = 1
#   for i in range(r):
#       ans = (ans*(n-i))//(i+1)
#   return ans
# ______________________________________________________________________________________________________
# For smallest prime factor of a number
# M = 5*10**5+100
# spf = [i for i in range(M)]
# def spfs(M):
#     for i in range(2,M):
#         if spf[i]==i:
#             for j in range(i*i,M,i):
#                 if spf[j]==j:
#                     spf[j] = i

#     return
# spfs(M)
# p = [0]*M
# for i in range(2,M):
#     p[i]+=(p[i-1]+(spf[i]==i))
# ______________________________________________________________________________________________________
# def gtc(p):
#     print('Case #'+str(p)+': ',end='')
# ______________________________________________________________________________________________________
tc = 1
tc = int(input())
for test in range(1,tc+1):
    n = int(input())
    a = inp()
    a.sort()
    # b = a.copy()
    # for i in range(1,n):
        # b[i]+=b[i-1]
    ans = 0
    cnt = 0
    for i in range(2,n):
        cnt+=a[i-2]
        ans-=cnt
        ans+=cnt-(a[i]*(i-1))
        # print(ans,cnt,a[i],a[i-1])
    print(ans)