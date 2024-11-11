n=int(input())
l=list(map(int,input().split()))
dp=[0]*(n)
dp[0]=0
dp[1]=abs(l[0]-l[1])
for i in range(2,n):
    dp[i]=max(abs(l[i]-l[i-2])+dp[i-2],dp[i-1]+abs(l[i]-l[i-1]))
print(dp[-1])
