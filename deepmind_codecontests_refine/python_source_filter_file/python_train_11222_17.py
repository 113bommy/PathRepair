n=int(input())
h=[map(int,input().split())]
dp=[0]*n
for i in range(1,n):
  if h[i-1]>=h[i]:
    dp[i]=dp[i-1]+1
print(max(dp))
