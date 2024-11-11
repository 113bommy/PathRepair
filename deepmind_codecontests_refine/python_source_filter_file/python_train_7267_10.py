N = int(input())
a = list(map(float, input().split()))
dp=[[[0.0] *(N+2) for _ in range(N+2)] for _ in range(N+2)]
one,two,three=a.count(1),a.count(2),a.count(3)
for k in range(three+1):
    for j in range(N+1):
        for i in range(N+1):
            if k==0 and j==0 and i==0:
                continue
            num=N
            if i>0:
                num+=dp[i-1][j][k]*i
            if j>0:
                num+=dp[i+1][j-1][k]*j
            if k>0:
                num+=dp[i][j+1][k-1]*k
            dp[i][j][k]=num/(k+j+i)
print(dp[one][two][three])