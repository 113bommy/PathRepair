import sys
input = sys.stdin.readline
n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in range(n)]
ab = [(x,y) for x,y in zip(a,b)]
from operator import itemgetter
ab = tuple(sorted(ab,key=itemgetter(0),reverse=True))
dp = [[-10**14]*(n+1) for i in range(n+1)]
dp[0][0] = 0
for i in range(n):
  for j in range(i+2):
    if j >= 1:
      dp[i+1][j] = max(dp[i][j]+ab[i][0]*abs(ab[i][1]-(n-1-(i-j))),dp[i][j-1]+ab[i][0]*abs(ab[i][1]+1-j))
    if j == 0:
      dp[i+1][0] = dp[i][0] + ab[i][0]*abs(ab[i][1]-(n-1-i))
print(max(dp[n]))