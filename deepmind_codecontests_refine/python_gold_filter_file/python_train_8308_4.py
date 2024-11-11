N = int(input())
L = []
for i in range(N):
  L.append(int(input()))
TF = [False]*(N+1)
dp = [0]*(N+1)
for i in range(N):
  TF[L[i]] = True
  if TF[L[i]-1] == True:
    dp[L[i]] = dp[L[i]-1]+1
print(N-max(dp)-1)