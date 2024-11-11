import sys
sys.setrecursionlimit(160000)

N = int(input())
A = [int(a) for a in input().split()]

dp = [[0]*N for _ in range(N)]
flag = [[False]*N for _ in range(N)]
S = [0]*(N+1)

for i in range(N):
    flag[i][i] = True

S[0] = A[0]
for i in range(N):
    S[i+1] = S[i]+A[i]
    
def f(l, r):
    if flag[l][r]:
        return dp[l][r]
    flag[l][r] = True
    res = 10**12
    for m in range(l, r):
        res = min(res, f(l, m)+f(m+1, r))
    dp[l][r] = res+S[r+1]-S[l]
    return dp[l][r]

print(f(0, N-1), dp)