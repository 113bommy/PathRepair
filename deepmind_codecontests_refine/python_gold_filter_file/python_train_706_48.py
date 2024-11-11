n,k = map(int,input().split())
A = list(map(int,input().split()))
mod = 10**9 + 7
if n ==1: print(0 if k> A[0] else 1);exit()
dp = [[0]*(k+1) for _ in range(n)]
for i in range(A[0]+1):
    dp[0][i] = 1
for i in range(1,n):
    B = [0]
    for j in range(k+1):
        B.append(B[-1] + dp[i-1][j])
        B[-1]%=mod
    for j in range(k+1):
        dp[i][j] += B[j+1]-B[max(0,j-A[i])]
        dp[i][j] %= mod
print(dp[-1][-1]%mod)