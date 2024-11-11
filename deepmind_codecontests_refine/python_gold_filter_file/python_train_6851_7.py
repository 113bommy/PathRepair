import sys
input = sys.stdin.readline
n = int(input())
a = [int(input()) for i in range(n)]
b = [0]*n
for i in range(n):
  if a[i]%2:
    b[i] = 1
  elif a[i]:
    b[i] = 2
DP = [[10**18 for i in range(5)] for j in range(n+1)]
for i in range(5):
    DP[0][i] = 0
for i in range(1,n+1):
  for j in range(5):
    for k in range(j,5):
      if k == 0 or k == 4:
        DP[i][k] = min(DP[i][k],DP[i-1][j]+a[i-1])
      elif k == 1 or k == 3:
        DP[i][k] = min(DP[i][k],DP[i-1][j]+abs(b[i-1]-2))
      else:
        DP[i][k] = min(DP[i][k],DP[i-1][j]+abs(b[i-1]-1))
print(min(DP[n]))