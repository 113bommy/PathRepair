n=int(input())
l=list(map(int,input().split()))
dp=[0]*(n)
dp[0]=0
dp[1]=abs(l[0]-l[1])
for i in range(1,n):
    dp[i]=min(abs(l[i]-l[i-2])+dp[i-2],abs(l[i]-l[i-1])+dp[i-1])
print(dp[-1])