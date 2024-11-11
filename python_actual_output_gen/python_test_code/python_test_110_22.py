h,n=map(int,input().split())
dp=[10**10]*(h+1)
dp[0]=1
X=[]
for i in range(n):
    a,b=map(int,input().split())
    X.append([a,b])


for j in range(n):
    for i in range(h):
        k=min(i+X[j][0],h)
        dp[k]=min(dp[k],dp[i]+X[j][1])
print(dp[h])