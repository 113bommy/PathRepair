import sys
sys.setrecursionlimit(10000)
n = int(input())
*A, = map(int, input().split())
A = [(a, i) for i, a in enumerate(A)]
A.sort(reverse=True)
DP = [[None for r in range(n+1)] for l in range(n+1)]

def dp(l, r):
    if l == r:
        DP[l][r] = 0
    if DP[l][r] != None:
        return DP[l][r]
    a, i = A[n-(r-l)]
    x = dp(l+1, r)+a*abs(i-l)
    y = dp(l, r-1)+a*abs(i-(r-1))
    DP[l][r] = max(x, y)
    return DP[l][r]

print(dp(0, n))