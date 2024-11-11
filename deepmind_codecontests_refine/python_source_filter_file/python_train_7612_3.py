n,l,r=map(int,input().split())
pri=10**9+7
if(l%3==0):
    k1=r//3-l//3+1
else:
    k1=r//3-l//3

j=l-1
q=r-1
if(j%3==0):
    k2=q//3-j//3+1
else:
    k2=q//3-j//3
j=l-2
q=r-2
if(q%3==0):
    k3=q//3-j//3+1
else:
    k3=q//3-j//3
dp=[[0 for i in range(n+1)] for i in range(3)]
dp[0][1]=k1
dp[1][1]=k2
dp[2][1]=k3
for i in range(2,len(dp[0])):
    dp[0][i]=(dp[0][i-1]*k1)+(dp[1][i-1]*k3)+(dp[2][i-1]*k2)
    dp[1][i]=(dp[1][i-1]*k1)+(dp[2][i-1]*k3)+(dp[0][i-1])*k2
    dp[2][i]=(dp[2][i-1]*k1)+(dp[0][i-1]*k3)+(dp[1][i-1]*k2)
    dp[0][i]%=pri
    dp[1][i]%=pri
    dp[2][i]%=pri
print(dp[0][-1])
