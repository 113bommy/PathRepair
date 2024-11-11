import sys
INF = 10**20
MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import gcd
from math import ceil
from collections import defaultdict as dd, Counter
from bisect import bisect_left as bl, bisect_right as br


"""
Facts and Data representation
Constructive? Top bottom up down
"""
def solve():
  n, m = I()
  a = []
  for i in range(n):
    a.append(I())
  ans = [[0] * m for i in range(n)]
  for i in range(n):
    for j in range(m):
      ans[i][j] = 4
  for i in range(n):
    if i == 0 or i == n - 1:
      ans[i][0] = ans[i][m - 1] = 2
    else:
      ans[i][0] = ans[i][m - 1] = 3

  for i in range(1, m - 1):
    ans[0][i] = ans[n - 1][i] = 2

  for i in range(n):
    for j in range(m):
      if ans[i][j] < a[i][j]:
        print('NO')
        return
  print('YES')
  for i in ans:
    print(*i)

t, = I()
while t:
  t -= 1
  solve()