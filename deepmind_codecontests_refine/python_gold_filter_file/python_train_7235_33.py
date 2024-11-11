from collections import *
from itertools import *
from random import *
from bisect import *
from string import *
from queue import *
from heapq import *
from math import *
from re import *
from sys import *
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = input, lambda: list(map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9 + 7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))
def output(answer): stdout.write(str(answer))


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]


###########################---Test-Case---#################################
"""

If you Know me , Then you probably don't know me !

"""
###########################---START-CODING---##############################


# n, m = zzz()


# for _ in range(m):
#     x, y, w = zzz()
#     try:
#         graph[x]
#     except:
#         graph[x] = []
#     try:
#         graph[y]
#     except:
#         graph[y] = []
#     graph[x].append((y, w))
#     graph[y].append((x, w))


# path = [0] * (n + 1)
# dis = [float('inf')] * (n + 1)

# hp = [(0, 1)]

# while hp:
#     try:
#         dcur, cur = heappop(hp)
#         print(hp)
#         for d, w in graph[cur]:
#             if dcur + w < dis[d]:
#                 dis[d] = dcur + w
#                 path[d] = cur
#                 heappush(hp, (dis[d], d))
#                 print(hp)
#     except:
#         exit(print(-1))


# l = [n]
# x = n
# print(path)
# print(dis)
# if path[n] > 0:
#     while x != 1:
#         x = path[x]
#         l.append(x)
#     print(*l[::-1])
# else:
#     print(-1)


# #
# root = {}


# def build(string, index):
#     node = root
#     for letter in string:
#         if letter not in node:
#             node[letter] = {}
#         node = node[letter]
#     node['index'] = index


# def contains(string):
#     node = root
#     for letter in string:
#         if letter not in node:
#             return False
#         node = node[letter]
#     return node['index']


# n, l = zzz()
# s = fast() * 2
# q = int(fast())
# for i in range(q):
#     build(input(), i + 1)
# pos = False
# ans = [0] * n
# for i in range(l):
#     pos = True
#     found = [False] * (q + 1)
#     for j in range(n):
#         loc = contains(s[i + j * l: i + (j + 1) * l])
#         if not loc or found[loc]:
#             pos = False
#             break
#         found[loc] = True
#         ans[j] = loc
#     if pos:
#         break
# if not pos:
#     print("NO")
# else:
#     print("YES")
#     # print(' '.join([str(x) for x in ans]))
#     for i in ans:
#         print(i)

# num = int(z())

# for _ in range(num):
#     a, b = zzz()
#     arr = zzz()
#     for i in arr:
#         while 0 < i < b * 10 and i % b:
#             i -= 10
#         if i < b:
#             print('NO')
#         else:
#             print('YES', i)
# num = int(z())


# def has(x, d):
#     return str(x).count((str(d))) > 0


# for _ in range(num):
#     arr = zzz()
#     dp = [0] * (1005)
#     dp[0] = 1
#     for i in range(1, 1002):
#         if has(i, d):
#             for j in range(0, 1003 - i):
#                 if dp[j] > 0:
#                     dp[i + j] = 1
#     for i in arr:
#         if i > 1000 or dp[x]:
#             print('YES')
#         else:
#             print('NO')

# n, m = zzz()
# arr = list(fast() + '***')

# k, res = 0, []

# for i in range(n):
#     if arr[i] == arr[i + 1] == '.':
#         k += 1
# for i in range(m):
#     x, y = fast().split(' ')
#     x = int(x) - 1
#     if arr[x] == '.':
#         if y != '.':
#             if x > 0 and arr[x - 1] == '.':
#                 k -= 1
#             if x < n - 1 and arr[x + 1] == '.':
#                 k -= 1
#     else:
#         if y == '.':
#             if x > 0 and arr[x - 1] == '.':
#                 k += 1
#             if x < n - 1 and arr[x + 1] == '.':
#                 k += 1
#     print(k)
#     arr[x] = y


n = int(z())

arr = zzz()

ans = abs(arr[0])

for i in range(1, n):
    ans += abs(arr[i] - arr[i - 1])
print(ans)
