N = int(input())
a = list(map(int,input().split()))
I = 0
J = 0
K = 0
for i in range(N):
    if a[i] == 1:
        I += 1
    if a[i] == 2:
        J += 1
    if a[i] == 3:
        K += 1

dp = [[[0.0]*(N+2) for _ in range(N+2)] for _ in range(N+2)]
for k in range(K+1):
    for j in range(J+K+1):
        if j+k > N:
            break
        for i in range(N+1):
            S = i+j+k
            if S > N:
                break
            if S == 0:
                continue
            dp[i][j][k] = (i*dp[i-1][j][k]+j*dp[i+1][j-1][k]+k*dp[i][j+1][k-1]+N)/S
print(dp[I][J][K])