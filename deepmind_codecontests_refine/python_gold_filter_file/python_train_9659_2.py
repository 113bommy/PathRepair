N,mod=map(int,input().split())

DP=[[0]*(N+5) for i in range(3*N+5)]
DP[0][0]=1

for i in range(3*N):
    for j in range(N+1):
        DP[i][j]%=mod
        DP[i+1][j]+=DP[i][j]
        DP[i+2][j+1]+=((3*N-i)-1)*DP[i][j]
        DP[i+3][j+1]+=((3*N-i)-1)*((3*N-i)-2)*DP[i][j]

ANS=0
for i in range(N+1):
    ANS+=DP[3*N][i]
print(ANS%mod)