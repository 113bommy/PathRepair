import sys
input = sys.stdin.readline

N = int(input())
a = list(map(int, input().split()))
IJK = [0,0,0]
for i in range(N):
    IJK[a[i]-1]+=1

dp = [[[0]*(N+3) for _ in range(N+3)] for _ in range(N+3)]

for k in range(N+1):
    for j in range(N+1):
        for i in range(N+1):
            if i+j+k > N: continue
            if i+j+k == 0: continue
            tmp = N
            if i>0: tmp += i*dp[i-1][j][k]
            if j>0: tmp += j*dp[i+1][j-1][k]
            if k>0: tmp += k*dp[i][j+1][k-1]
            dp[i][j][k] = tmp/(i+j+k)
print(dp[IJK[0]][IJK[1]][IJK[2]])


