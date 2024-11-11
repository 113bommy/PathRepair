from sys import stdin
from collections import deque
# https://codeforces.com/contest/1354/status/D
mod = 10**9 + 7
import sys
import random
sys.setrecursionlimit(10**6)
from queue import PriorityQueue
from collections import Counter as cc
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






































#
#
# n = int(input())
# x = 0
# l = list(map(int,input().split()))
# for i in range(n):
#
#      x = l[i]|x
#
# z = list(bin(x)[2:])
# ha = z.copy()
# k = z.count('1')
# ans = 0
# # print(z)
# cnt = 0
# for i in range(20):
#
#
#         maxi = 0
#         idx = -1
#
#         for j in range(n):
#             k = bin(l[j])[2:]
#             k = '0'*(len(z) -len(k)) + k
#             cnt = 0
#             for i in range(len(z)):
#                 if k[i] == z[i] == '1':
#                     cnt+=1
#
#             maxi = max(maxi,cnt)
#             if maxi == cnt:
#                 idx = j
#         if idx!=-1:
#
#             k = bin(l[idx])[2:]
#             k = '0'*(len(z) -len(k)) + k
#
#             for i in range(len(z)):
#                 if k[i] == z[i] == '1':
#                     z[i] = '0'
#             l[idx] = 0
#
#
# ans = 0
# for i in range(len(z)):
#     if z[i] == '0' and ha[i] == '1':
#         ans+=1
# flip = 0
# for i in range(ans):
#     flip+=2**i
#
#
#
# print(flip)

# def search(k,l,low):
#
#     high = len(l)-1
#     z = bisect_left(l,k,low,high)
#
#     return z
#
#
#
#
#
#
# n,x = map(int,input().split())
#
# l = list(map(int,input().split()))
#
# prefix = [0]
# ha = [0]
# for i in l:
#     prefix.append(i + prefix[-1])
#     ha.append((i*(i+1))//2 + ha[-1])
# fin = 0
# print(prefix)
# for i in range(n):
#     ans = 0
#     if l[i]<x:
#
#
#         if prefix[-1]-prefix[i]>=x:
#
#             z = search(x+prefix[i],prefix,i+1)
#             print(z)
#             z+=i+1
#             k1 = x-(prefix[z-1]-prefix[i])
#             ans+=ha[z-1]
#             ans+=(k1*(k1+1))//2
#
#
#         else:
#             z1 = x - (prefix[-1]-prefix[i])
#             z = search(z1,prefix,1)
#
#             k1 = x-prefix[z-1]
#             ans+=ha[z-1]
#             ans+=(k1*(k1+1))//2
#
#
#
#
#     elif l[i]>x:
#         z1 = ((l[i])*(l[i]+1))//2
#         z2 = ((l[i]-x)*(l[i]-x+1))//2
#         ans+=z1-z2
#     else:
#         ans+=(x*(x+1))//2





# t = int(input())
#
# for _ in range(t):
#
#     s = list(input())
#     ans = [s[0]]
#
#     for i in range(1,len(s)-1,2):
#         ans.append(s[i])
#
#     ans.append(s[-1])
#     print(''.join(ans))
#
#
#
# t = int(input())
#
# for _ in range(t):
#
#     n = int(input())
#     l = list(map(int,input().split()))
#     ans = 0
#     for i in range(n):
#         if l[i]%2!=i%2:
#             ans+=1
#
#     if ans%2 == 0:
#         print(ans//2)
#     else:
#        print(-1)


# t = int(input())
#
# for _ in range(t):
#
#     n,k = map(int,input().split())
#     s = input()
#
#
#     ans = 0
#     ba = []
#     for i in range(n):
#         if s[i] == '1':
#             ba.append(i)
#     if ba == []:
#         for i in range(0,n,k+1):
#             ans+=1
#
#         print(ans)
#         continue
#
#     i = s.index('1')
#     c = 0
#     for x in range(i-1,-1,-1):
#         if c == k:
#             c = 0
#             ans+=1
#         else:
#             c+=1
#
#
#     while i<len(s):
#         count = 0
#         dis = 0
#         while s[i] == '0':
#             dis+=1
#             if dis == k:
#                 dis = 0
#                 count+=1
#             if dis<k and s[i] == '1':
#                 count-=1
#                 break
#             i+=1
#             if i == n:
#                 break
#         i+=1
#
#     print(ans)
#
#
#
#

# q1

# def poss1(x):
#     cnt = 1
#     mini = inf
#     for i in l:
#         if cnt%2 != 0:
#           cnt+=1
#         else:
#             if i<=x:
#                 cnt+=1
#                 mini = min()
#         if cnt  == k:
#             return
#
#     return -1
#
#
#
#
# def poss2(x):
#     cnt = 1
#     for i in l:
#         if cnt%2 == 0:
#             cnt+=1
#         else:
#             if i<=x:
#                 cnt+=1
#         if cnt  == k:
#             return
#
#     return -1
#
#
#
# n,k = map(int,input().split())
# l = list(map(int,input().split()))
#
# z1 = min(l)
# z2 = max(l)







# t = int(input())
#
# for _ in range(t):
#
#     n,k = map(int,input().split())
#     l = list(map(int,input().split()))
#
#     for i in range(n):
#         z = l[i]%k
#
#         if z!=0:
#
#             l[i] = k-z
#         else:
#             l[i] = 0
#
#     l.sort()
#     count = 0
#     ans = 0
#     x = 0
#     print(l)
#     for i in range(n):
#
#             z = l[i]
#             if z == 0:
#                 continue
#             if x>z:
#                 z2 = ceil((x-l[i])/k)
#                 z1 = l[i] + k*z2
#                 # print(x,z1)
#                 ans += z1-x + 1
#                 x = z1+1
#             elif z == x:
#                 ans+=1
#                 x+=1
#             else:
#
#                 ans += z-x + 1
#                 x = z+1
#             # print(i,x)
#             print(ans)
#
#
#
#     print(ans)


# t = int(input())
#
# for _ in range(t):
#
#     n = int(input())
#     seti = set()
#     ans = []
#     for i in range(1,1001):
#         if i not in seti:

# def dfs_cycle(u, p, color,
#               mark, par):
#     global cyclenumber
#
#     # already (completely) visited vertex.
#     if color[u] == 2:
#         return
#
#     # seen vertex, but was not
#     # completely visited -> cycle detected.
#     # backtrack based on parents to
#     # find the complete cycle.
#     if color[u] == 1:
#         cyclenumber += 1
#         cur = p
#         mark[cur] = cyclenumber
#
#         # backtrack the vertex which are
#         # in the current cycle thats found
#         while cur != u:
#             cur = par[cur]
#             mark[cur] = cyclenumber
#
#         return
#
#     par[u] = p
#
#     # partially visited.
#     color[u] = 1
#
#     # simple dfs on graph
#     for v in hash[u]:
#
#         # if it has not been visited previously
#         if v == par[u]:
#             continue
#         dfs_cycle(v, u, color, mark, par)
#
#         # completely visited.
#     color[u] = 2
#
# def printCycles(edges, mark):
#
#     # push the edges that into the
#     # cycle adjacency list
#     for i in range(1, edges + 1):
#         if mark[i] != 0:
#             cycles[mark[i]].append(i)
#
#             # print all the vertex with same cycle
#     for i in range(1, cyclenumber + 1):
#
#         # Print the i-th cycle
#         print("Cycle Number %d:" % i, end = " ")
#         for x in cycles[i]:
#             print(x, end = " ")
#         print()
#
# t = int(input())
#
# for _ in range(t):
#
#     n,m = map(int,input().split())
#
#     hash = defaultdict(list)
#     seti = set()
#     for i in range(m):
#
#         type,a,b = map(int,input().split())
#         hash[a].append(b)
#         hash[b].append(a)
#         if type == 1:
#             seti.add((a,b))
#
#     cycles = defaultdict(list)
#     color = defaultdict(int)
#     par = defaultdict(int)
#     mark = defaultdict(int)
#     cyclenumber = 0
#     dfs_cycle(1, 0, color, mark, par)
#     printCycles(m, mark)
#
#
#
#
#
#



































































































































































    # binary lifting Technique

# n = int(input())
# max_log = int(input())
# dp = []
# for i in range(n+1):
#     c = [0]*(max_log + 1)
#     dp.append(c)
# par = []
# for i in range(1,n+1):
#     for j in range(0,n+1):
#         if (1<<j)>n:
#             break
#         dp[i][j] = -1
#
# for i in range(1,n+1):
#     dp[i][0] = par[i]
#
# for j in range(1,n+1):
#     if (1<<j)>n:
#         break
#     for i in range(1,n+1):
#         if dp[i][j-1]!=-1:
#             dp[i][j] = dp[dp[i][j-1]][j-1]
#
# level = defaultdict(int)
# def lca(u,v):
#  if level[u] < level[v]:
#      u,v = v,u
#
#  dist = level[u] - level[v]
#  while dist>0:
#      raise_by = int(log2(dist))
#      u = dp[u][raise_by]
#      dist-=1<<raise_by
#
#  if u == v:
#      return u
#
#  for j in range(max_log,-1,-1):
#
#      if dp[u][j]!=-1 and dp[u][j]!=dp[v][j]:
#          u = dp[u][j]
#          v = dp[v][j]
#
#
#
#
#
#
#  return par[u]


# n = int(input())

# t = int(input())
#
# for _ in range(t):
#
#     n = int(input())
#     l = list(map(int,input().split()))
#     ans = ['']*(n+1)
#     cnt = 1
#     id = 99
#     for i in range(n-1):
#         a = l[i]
#         s1,s2 = ans[i],ans[i+1]
#         if a == 0:
#
#             ans[i] = chr((id)%97 + 97)*(cnt)
#             if id%97 == 0:
#                 cnt+=1
#             id+=1
#
#         elif s1 == 0:
#             ans[i],ans[i+1] = 'a'*a,'a'*a
#         elif len(s1)<=a:
#             ans[i] = s1 + 'a'*(a-len(s1))
#             ans[i+1] = ans[i]
#         else:
#             ans[i+1] = s1[:a]
#     a = l[-1]
#     s1 = ans[-2]
#
#     if a == 0:
#         ans[-2] =  chr((id+1)%97 + 97)*(cnt)
#         if id%97 == 0:
#             cnt+=1
#         id+=1
#         ans[-1] =  chr((id+1)%97 + 97)*(cnt)
#     elif len(s1)<=a:
#         ans[-2] = s1 + 'a'*(a-len(s1))
#         ans[-1] = ans[-2]
#     else:
#         ans[-1] = s1[:a]
#     for i in ans:
#         print(i)
#
#
#

# q1

# class Solution:
#     # @param A : string
#     # @param B : list of strings
#     # @return a list of strings
#     def wordBreak(self, A, B):



# count = 0
#
#
# for i in range(6,150):
#     for j in range(7,150):
#         for k in range(8,150):
#             for e in range(1,150):
#                 if i+j+k+e == 150:
#                     count+=1
#
# print(count)

# q1
# t = int(input())
# for _ in range(t):
#
#     n = int(input())
#     l = [i+1 for i in range(n)]
#     l.reverse()
#
#
#
#     print(*l)


# q2

# def solvehist(l):
#
#     stack = []
#     i = 0
#     maxi = 0
#     while i<len(l):
#
#         if stack == []:
#             stack.append(i)
#             i+=1
#         elif l[stack[-1]]<=l[i]:
#             stack.append(i)
#             i+=1
#
#         else:
#             z = stack.pop()
#             if stack:
#               area = l[z] * (i-stack[-1]-1)
#             else:
#                 area = l[z]*(i)
#             maxi = max(maxi,area)
#
#     while stack:
#         z = stack.pop()
#         if stack:
#             area = l[z] * (i-stack[-1]-1)
#         else:
#             area = l[z]*(i)
#         maxi = max(maxi,area)
#
#     return maxi



# Trie for arrays
# class Node():
#     def __init__(self,value):
#         self.value = value
#         self.left = None
#         self.right = None
#
# def insert(n,head):
#     cur_node = head
#
#     for i in range(31,-1,-1):
#         b = (n>>i)&1
#
#         if b == 0:
#             if cur_node.left == None:
#                 cur_node.left = Node(b)
#
#             cur_node = cur_node.left
#         elif b == 1:
#             if cur_node.right == None:
#                 cur_node.right = Node(b)
#
#             cur_node = cur_node.right
#
# def sol(n,head):
#     cur_node = head
#     st = '0'
#
#     for i in range(31,-1,-1):
#         b = (n>>i)&1
#         if b == 0:
#
#             if cur_node.left!=None:
#
#                 cur_node = cur_node.left
#                 st+='0'
#             else:
#                 if cur_node.right != None:
#                     cur_node = cur_node.right
#                     st+='1'
#
#         elif b == 1:
#             if cur_node.right != None:
#                 cur_node = cur_node.right
#                 st+='1'
#             else:
#                 if cur_node.left != None:
#                     cur_node = cur_node.left
#                     st+='0'
#
#
#     ans = int(st,2)
#     return ans
#
#
#
# head = Node(0)


# Trie For strings

# from collections import defaultdict
# class Trie:
#
#     def __init__(self,st):
#         self.child = []
#         self.terminate  = False
#         self.st = st
#         self.val = 0
#
# def counti(cur_node):
#     ans = 0
#     if cur_node.child == []:
#         return 0
#
#
#
#
#
#     for i in cur_node.child:
#         if i.terminate == True:
#
#             ans += i.val+counti(i)
#         else:
#             ans += counti(i)
#
#     return ans
#
#
#
#
# def insert(s,head,val):
#
#     cur_node = head
#
#     for i in s:
#         flag =  0
#         for j in cur_node.child:
#             # print(i,j.st)
#             if j.st == i:
#
#                 cur_node = j
#                 flag = 1
#                 break
#         if not flag:
#             z = Trie(i)
#             cur_node.child.append(z)
#
#             cur_node = z
#
#     cur_node.terminate = True
#     cur_node.val = val
#
#
# def query(s,head):
#     cur_node = head
#
#     for i in s:
#         flag = 0
#         for j in cur_node.child:
#             if j.st == i:
#                 cur_node = j
#                 flag = 1
#                 break
#         if not flag:
#             return 0
#
#     count = cur_node.val if cur_node.terminate == True else 0
#
#     count+=counti(cur_node)
#
#     return count
#
#
# hash = defaultdict(int)
#
#
# head = Trie('0')
# n,q = map(int,input().split())
# for i in range(n):
#     hash[input()]+=1
#
# for i in hash:
#     insert(i,head,hash[i])
#
# for i in range(q):
#     print(query(input(),head))

def bfs(n):

    que = [n]
    boo[n] = True
    ans = 0
    while que:
        z = que.pop(0)
        ans+=1
        for i in hash[z]:
            if not boo[i]:
                boo[i] = True
                que.append(i)


    return ans



t = int(input())
ha = []
for _ in range(t):

   n = int(input())
   l = list(input())
   ans = 0
   if len(set(l)) == 1:
       print(ceil(n/3))
       continue

   hash = defaultdict(list)
   ha = defaultdict(bool)
   for i in range(n):
       if l[i] == l[(i+1)%n]:
           hash[i].append((i+1)%n)
           ha[(i+1)%n] = True


   boo = defaultdict(bool)

   for i in range(n):
       if not boo[i] and not ha[i]:
           z = bfs(i)
           # print(z)

           ans+=z//3

   print(ans)







