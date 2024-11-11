N = int(input())
p = list(map(float,input().split()))
DP = [[0 for i in range((N+1)//2)] for i in range(N)]
DP[0][0] = p[0]
if N > 1:
    DP[0][1] = 1-p[0]
for i in range(1,N):
    for j in range((N+1)//2):
        DP[i][j] += p[i]*DP[i-1][j]
        if j != 0:
            DP[i][j] += (1-p[i])*DP[i-1][j-1]
print(sum(DP[-1]))