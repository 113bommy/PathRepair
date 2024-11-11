import sys
input = sys.stdin.readline
from itertools import accumulate

def merge(x, y):
  D = sorted([dp[x][0], dp[x][1], dp[y][0], dp[y][1]], reverse=True)
  return (D[0], D[1])
  
n = int(input())
A = tuple(map(int, input().split()))
dp = [(a, 0) for a in A]
for j in range(n):
  for i in range(1<<n):
    if i & (1<<j):
      dp[i] = merge(i, i & ~(1<<j))
L = tuple(accumulate((sum(d) for d in dp), max))
print(*L[1:], sep="\n")