N = int(input())
A = list(map(int, input().split()))
A = sorted([(a, p) for p, a in enumerate(A)], reverse=True)
dp = [[0]*(i+1) for i in range(N+1)]
for z in range(N):
    for y in range(z+1):
        dp[z+1][y] = max(A[z][0]*(A[z][1]-(z-y))+dp[z][y],dp[z+1][y])
        dp[z+1][y+1]= A[z][0]*((N-y-1)-A[z][1])+dp[z][y]
print(max(dp[-1]))