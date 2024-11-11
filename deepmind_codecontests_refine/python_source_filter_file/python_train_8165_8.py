n = int(input())
lis = list(map(int,input().split()))
has=[0]*(100100)
for i in lis:
    has[i]+=1
dp=[0]*(100100)
c=0
dp[1]=has[1]    
for i in range(2,100002):
    dp[i]=max(dp[i-2]+has[i]*i,dp[i-1])    
print(dp[n])       