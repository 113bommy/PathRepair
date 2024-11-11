from sys import stdin
mod = 10**9+7
n,k = map(int,stdin.readline().split())
arr = list(map(int,stdin.readline().split()))
dp = [[0]*(k+1) for _ in range(n+1)]
dp[0][0] = 1
for i in range(1,n+1):
    lst = [0]
    for j in range(k+1):
        lst.append((lst[-1]+dp[i-1][j])%mod)
        dp[i][j] = lst[j+1]-lst[max(0,j-arr[i-1])]
print(dp[-1][-1])