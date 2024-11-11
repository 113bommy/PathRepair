from sys import stdin
from collections import deque
# https://codeforces.com/contest/1354/status/D
mod = 10**9 + 7
import sys
import random
# sys.setrecursionlimit(10**6)
from queue import PriorityQueue
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# # l = list(map(int,input().split()))
# from itertools import permutations
import heapq
# input = lambda: sys.stdin.readline().rstrip()
input = lambda : sys.stdin.readline().rstrip()
from sys import stdin, stdout
from heapq import heapify, heappush, heappop
from itertools import permutations
from math import factorial as f

# def ncr(x, y):
#     return f(x) // (f(y) * f(x - y))
def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p

import sys

# input = sys.stdin.readline
# LCA
# def bfs(na):
#
#     queue = [na]
#     boo[na] = True
#     level[na] = 0
#
#     while queue!=[]:
#
#         z = queue.pop(0)
#
#         for i in hash[z]:
#
#             if not boo[i]:
#
#                 queue.append(i)
#                 level[i] = level[z] + 1
#                 boo[i] = True
#                 dp[i][0] = z
#
#
#
# def prec(n):
#
#     for i in range(1,20):
#
#         for j in range(1,n+1):
#             if dp[j][i-1]!=-1:
#                 dp[j][i] = dp[dp[j][i-1]][i-1]
#
#
# def lca(u,v):
#     if level[v] < level[u]:
#         u,v = v,u
#
#     diff = level[v] - level[u]
#
#
#     for i in range(20):
#         if ((diff>>i)&1):
#             v = dp[v][i]
#
#
#     if u == v:
#         return u
#
#
#     for i in range(19,-1,-1):
#         # print(i)
#         if dp[u][i] != dp[v][i]:
#
#             u = dp[u][i]
#             v = dp[v][i]
#
#
#     return dp[u][0]
#
# dp = []
#
#
# n = int(input())
#
# for i in range(n + 10):
#
#     ka = [-1]*(20)
#     dp.append(ka)


# class FenwickTree:
#     def __init__(self, x):
#         """transform list into BIT"""
#         self.bit = x
#         for i in range(len(x)):
#             j = i | (i + 1)
#             if j < len(x):
#                 x[j] += x[i]
#
#     def update(self, idx, x):
#         """updates bit[idx] += x"""
#         while idx < len(self.bit):
#             self.bit[idx] += x
#             idx |= idx + 1
#
#     def query(self, end):
#         """calc sum(bit[:end])"""
#         x = 0
#         while end:
#             x += self.bit[end - 1]
#             end &= end - 1
#         return x
#
#     def find_kth_smallest(self, k):
#         """Find largest idx such that sum(bit[:idx]) <= k"""
#         idx = -1
#         for d in reversed(range(len(self.bit).bit_length())):
#             right_idx = idx + (1 << d)
#             if right_idx < len(self.bit) and k >= self.bit[right_idx]:
#                 idx = right_idx
#                 k -= self.bit[idx]
#         return idx + 1



# import sys
# def rs(): return sys.stdin.readline().strip()
# def ri(): return int(sys.stdin.readline())
# def ria(): return list(map(int, sys.stdin.readline().split()))
# def prn(n): sys.stdout.write(str(n))
# def pia(a): sys.stdout.write(' '.join([str(s) for s in a]))
#
#
# import gc, os
#
# ii = 0
# _inp = b''
#
#
# def getchar():
#     global ii, _inp
#     if ii >= len(_inp):
#         _inp = os.read(0, 100000)
#         gc.collect()
#         ii = 0
#     if not _inp:
#         return b' '[0]
#     ii += 1
#     return _inp[ii - 1]
#
#
# def input():
#     c = getchar()
#     if c == b'-'[0]:
#         x = 0
#         sign = 1
#     else:
#         x = c - b'0'[0]
#         sign = 0
#     c = getchar()
#     while c >= b'0'[0]:
#         x = 10 * x + c - b'0'[0]
#         c = getchar()
#     if c == b'\r'[0]:
#         getchar()
#     return -x if sign else x

# fenwick Tree

# n,q = map(int,input().split())
#
#
# l1 = list(map(int,input().split()))
#
# l2 = list(map(int,input().split()))
#
# bit = [0]*(10**6 + 1)
#
# def update(i,add,bit):
#
#     while i>0 and i<len(bit):
#
#         bit[i]+=add
#         i = i + (i&(-i))
#
#
# def sum(i,bit):
#     ans = 0
#     while i>0:
#
#         ans+=bit[i]
#         i = i - (i & ( -i))
#
#
#     return ans
#
# def find_smallest(k,bit):
#
#     l = 0
#     h = len(bit)
#     while l<h:
#
#         mid = (l+h)//2
#         if k <= sum(mid,bit):
#             h = mid
#         else:
#             l = mid + 1
#
#
#     return l
#
#
# def insert(x,bit):
#     update(x,1,bit)
#
# def delete(x,bit):
#     update(x,-1,bit)
# fa = set()
#
# for i in l1:
#     insert(i,bit)
#
#
# for i in l2:
#     if i>0:
#         insert(i,bit)
#
#     else:
#         z = find_smallest(-i,bit)
#
#         delete(z,bit)
#
#
# # print(bit)
# if len(set(bit)) == 1:
#     print(0)
# else:
#     for i in range(1,n+1):
#         z = find_smallest(i,bit)
#         if z!=0:
#             print(z)
#             break
#

# service time problem


# def solve2(s,a,b,hash,z,cnt):
#     temp = cnt.copy()
#     x,y = hash[a],hash[b]
#     i = 0
#     j = len(s)-1
#
#     while z:
#
#         if s[j] - y>=x-s[i]:
#             if temp[s[j]]-1 == 0:
#                 j-=1
#             temp[s[j]]-=1
#             z-=1
#
#
#         else:
#             if temp[s[i]]-1 == 0:
#                 i+=1
#
#             temp[s[i]]-=1
#             z-=1
#
#     return s[i:j+1]
#
#
#
#
#
# def solve1(l,s,posn,z,hash):
#
#     ans = []
#     for i in l:
#         a,b = i
#         ka = solve2(s,a,b,posn,z,hash)
#         ans.append(ka)
#
#         return ans
#
# def consistent(input, window, min_entries, max_entries, tolerance):
#
#     l = input
#     n = len(l)
#     l.sort()
#     s = list(set(l))
#     s.sort()
#
#     if min_entries<=n<=max_entries:
#
#         if s[-1] - s[0]<window:
#             return True
#         hash = defaultdict(int)
#         posn = defaultdict(int)
#         for i in l:
#             hash[i]+=1
#
#         z = (tolerance*(n))//100
#         poss_window = set()
#
#
#         for i in range(len(s)):
#                 posn[i] = l[i]
#                 for j in range(i+1,len(s)):
#                     if s[j]-s[i] == window:
#                         poss_window.add((s[i],s[j]))
#
#         if poss_window!=set():
#             print(poss_window)
#             ans = solve1(poss_window,s,posn,z,hash)
#             print(ans)
#
#
#         else:
#             pass
#
#     else:
#         return False
#
#
#
#
# l = list(map(int,input().split()))
#
# min_ent,max_ent = map(int,input().split())
# w = int(input())
# tol = int(input())
# consistent(l, w, min_ent, max_ent, tol)

# t = int(input())
#
# for i in range(t):
#
#     n,x = map(int,input().split())
#
#     l = list(map(int,input().split()))
#
#     e,o = 0,0
#
#     for i in l:
#         if i%2 == 0:
#             e+=1
#         else:
#             o+=1
#
#     if e+o>=x and o!=0:
#         z = e+o - x
#         if z == 0:
#             if o%2 == 0:
#                 print('No')
#             else:
#                 print('Yes')
#             continue
#         if o%2 == 0:
#             o-=1
#             z-=1
#             if e>=z:
#                 print('Yes')
#             else:
#                 z-=e
#                 o-=z
#                 if o%2!=0:
#                     print('Yes')
#                 else:
#                     print('No')
#
#         else:
#
#             if e>=z:
#                 print('Yes')
#             else:
#                 z-=e
#                 o-=z
#                 if o%2!=0:
#                     print('Yes')
#                 else:
#                     print('No')
#     else:
#         print('No')
#
#
#
#
#
#
#
# def dfs(n):
#     boo[n] = True
#     dp2[n] = 1
#     for i in hash[n]:
#         if not boo[i]:
#
#             dfs(i)
#             dp2[n] += dp2[i]


# t = int(input())
#
# for _ in range(t):
#
#     n = int(input())
#     l = list(map(int,input().split()))
#     l.sort()
#     if 0 in l:
#         for i in l:
#             k = []
#             if i!=0:
#              for j in l:
#                 k.append(i^j)
#
#              k.sort()
#              if k == l:
#
#                 break
#         if k!=l:
#             print(-1)
#             continue
#         else:
#             print(i)
#             continue
#
#
#     z = 0
#     ka = []
#     non = -1
#
#     for i in l:
#         z^=i
#         if i!=0 and non==-1:
#             non = i
#
#     for i in l:
#         ka.append(z^i)
#
#     ka.sort()
#     # print(z)
#     if ka == l:
#         if z!=0:
#            print(z)
#         else:
#             print(-1)
#
#
#     else:
#         print(-1)

t = int(input())

for _ in range(t):

    n = int(input())
    l = list(map(int,input().split()))
    hash = defaultdict(int)
    for i in range(n):
        hash[l[i]] = i
    i = 1
    flag = 0
    seti = set()
    while True:

        z = hash[1]
        cnt = i+1
        seti.add(i)
        for k in range(z+1,n):

            if l[k] in seti:
                break
            if l[k]!=cnt:
                flag = 1
                break
            seti.add(cnt)
            cnt+=1

        i+=1

        if flag:
            break
        if i == n+1:
            break


    if flag:
        print('No')
    else:
        print('Yes')




