N = int(input())
A = list(map(int,input().split()))

dp = [[[0 for k in range(N+1)] for j in range(N+1)] for i in range(N+1)]
dp[0][0][0] = 0

a,b,c = 0,0,0
for i in range(N):
    if A[i] == 1:
        a += 1
    elif A[i] == 2:
        b += 1
    else:
        c += 1

for k in range(c+1):
    for j in range(b+c-k+1):
        for i in range(a+b+c-k-j+1):
            if i==j==k==0:
                continue
            temp = N
            if i!=0:
                temp += dp[i-1][j][k]*i
            if j!=0:
                temp += dp[i+1][j-1][k]*j
            if k!=0:
                temp += dp[i][j+1][k-1]*k
            dp[i][j][k] = temp/(i+j+k)

print(dp[a][b][c])