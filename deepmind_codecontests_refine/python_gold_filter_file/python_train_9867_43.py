A,B,C,D = map(int,input().split())

MOD=998244353

#dp[i][j]たてにi回、横にj回追加したときの数
DP=[[0]*(D-B+1) for _ in range(C-A+1)]
DP[0][0]=1

for i in range(1,C-A+1):
    DP[i][0]=DP[i-1][0]*B
    DP[i][0]%=MOD
for i in range(1,D-B+1):
    DP[0][i]=DP[0][i-1]*A
    DP[0][i]%=MOD

for i in range(1,min(C-A,D-B)+1):
    for j in range(i,C-A+1):
        DP[j][i] = DP[j-1][i]*(B+i) + DP[j][i-1]*(A+j)-DP[j-1][i-1]*(B+i-1)*(A+j-1)
        DP[j][i]%=MOD
    for j in range(i+1,D-B+1):
        DP[i][j] = DP[i-1][j]*(B+j) + DP[i][j-1]*(A+i)-DP[i-1][j-1]*(B+j-1)*(A+i-1)
        DP[i][j]%=MOD


print(DP[-1][-1])
