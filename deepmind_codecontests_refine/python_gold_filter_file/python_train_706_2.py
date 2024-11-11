N, K = map(int, input().split())
A = list(map(int, input().split()))

from itertools import groupby, accumulate, product, permutations, combinations

def solve(N,K,A):
    mod = 10**9+7
    dp = [[0]*(K+1) for _ in range(N+1)] #dp[i][j] i人目まででj個を分ける場合の数
    dp[0][0] = 1
    for i in range(1,N+1):
        cum = list(map(lambda x:x%mod,accumulate(dp[i-1])))
        for j in range(K+1):
            dp[i][j] = cum[j]
            k = j-A[i-1]
            if k>0:
                dp[i][j] -= cum[k-1]
    ans = dp[N][K]%mod
    return ans
print(solve(N,K,A))