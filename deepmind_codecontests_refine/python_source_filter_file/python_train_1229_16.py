n, k = map(int, input().split())
stones = list(map(int, input.split()))

dp = [False for _ in range(k+1)]

for i in range(1, k+1):
  for j in stones:
    if i >= j and dp[i-j] == False:
      dp[i] = True
      continue
      
if dp[k]:
  print('First')
else:
  print('Second')