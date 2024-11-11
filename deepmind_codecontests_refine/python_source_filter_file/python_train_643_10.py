from sys import stdin
from collections import deque
mod = 10**9 + 7
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# # l = list(map(int,input().split()))
# from itertools import permutations

# a = int(input())
# b = int(input())
# c = int(input())
# d = int(input())
# e = int(input())
# f = int(input())
# ans = 0
#
# for i in range(d+1):
#     c = e*(min(i,a)) + f*(min(d-i,c,b))
#     ans = max(c,ans)
#     print(c,i,a)
#
# print(ans)
# ans1 = 0
# ans2 = 0
# def bfs(n):
#     global ans1
#     boo1[n] = True
#     queue = [n]
#
#     while queue:
#
#         z = queue.pop(0)
#         if len(hash[z]) == 0:
#             ans1+=1
#         for i in hash[z]:
#
#             if not boo1[i]:
#                 queue.append(i)
#                 boo1[i] = True
#
# def bfs1(n):
#     global ans2
#     boo2[n] = True
#     queue = [n]
#
#     while queue:
#
#         z = queue.pop(0)
#         if len(hash1[z]) == 0:
#             ans2+=1
#         for i in hash1[z]:
#
#             if not boo2[i]:
#                 queue.append(i)
#                 boo2[i] = True
#
#
#
#
#
#
#
#
#
# hash = defaultdict(list)
# hash1 = defaultdict(list)
# n,m = map(int,input().split())
#
# for i in range(m):
#     a,b = map(int,input().split())
#     hash[a].append(b)
#     hash1[b].append(a)
#
#
#
# boo1 = defaultdict(bool)
# boo2 = defaultdict(bool)
#
# for i in range(1,n+1):
#     if boo1[i] == False:
#         bfs(i)
#     if boo2[i] == False:
#         bfs1(i)
#
#
# print(max(ans1,ans2))
#
#
#
#


n,x,y = map(int,input().split())
cnt1 = 0
cnt2 = 0
cnt3 = 0
cnt4 = 0
ha = []
for i in range(n):
    a,b = map(int,input().split())
    ha.append([a,b])
    if a>x :
        cnt1+=1

    if y>b:
        cnt2+=1

    if a<x:
        cnt3+=1
    if y<b:
        cnt4+=1

z = max(cnt1,cnt2,cnt3,cnt4)
print(z)
if z == cnt1:
    mini = inf
    print(x-1,y)

elif z == cnt2:
    mini = inf
    print(x,y+1)


elif z == cnt3:
    mini = inf
    print(x+1,y)


elif z == cnt4:
    mini = inf
    print(x,y-1)
