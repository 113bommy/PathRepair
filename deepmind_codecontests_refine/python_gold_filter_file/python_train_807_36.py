n = int(input())
*A, = map(int, input().split())
# n = 6
# A = [8, 6, 9, 1, 2, 1]
# n = 4
# A = [1, 3, 4, 2]
A = [(a, i) for i, a in enumerate(A)]
A.sort(reverse=True)
DP = [[0 for r in range(n+1)] for l in range(n+1)]
for l in range(n):
    for r in range(n-l):
        a, i = A[l+r]
        DP[l+1][r] = max(DP[l+1][r], DP[l][r]+a*abs(i-l))
        DP[l][r+1] = max(DP[l][r+1], DP[l][r]+a*abs(i-(n-1-r)))
print(max([DP[l][n-l] for l in range(n)]))
