N = int(input())
arr = list(map(int, input().split()))

chisla = [0] * (max(arr)+1)

dp = [0] * (max(arr)+1)

for i in range(N):
    chisla[arr[i]] += 1

dp[0] = 0
dp[1] = chisla[1]
for i in range(2,max(arr)+1):
    dp[i] = max(dp[i-1], dp[i-2]+chisla[i]*i)
print(dp)
print(dp[max(arr)])