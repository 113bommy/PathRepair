import sys
input = sys.stdin.readline

n, k = map(int, input().split())
A = list(map(int, input().split()))
dp = [0]*(k+1)
for i in range(k+1):
  for a in A:
    if i-a >= 0 and (~dp[i-a]):
      dp[i] = 1
      break
result = dp[k]
if result:
  print("First")
else:
  print("Second")