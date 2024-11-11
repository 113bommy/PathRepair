n,a=map(int,input().split())
x=list(map(int,input().split()))
dp=[[[0 for i in range(2501)] for j in range(n+1)] for k in range(n+1)]
#dp[i][j][k]:=i枚目まで見てj枚選んで和がkとなるようなカードの取り方の数
dp[0][0][0]=1
for i in range(n):
    see=x[i]
    for j in range(i+2):
        for k in range(2501):
            dp[i+1][j][k]+=dp[i][j][k]
            if see>k or j==0:continue
            dp[i+1][j][k]+=dp[i][j-1][k-see]
ans=0
for i in range(1,n+1):
    ans+=dp[-1][i][i*a]
print(ans)