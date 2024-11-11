n = int(input())
*A, = map(int, input().split())
DP = [[0 for j in range(n+1)] for i in range(n+1)]
for l in range(1, n+1):
    for i in range(n-l+1):
        j = i+l
        DP[i][j] = max(A[i]-DP[i+1][j], A[j-1]-DP[i][j-1])
print(DP)