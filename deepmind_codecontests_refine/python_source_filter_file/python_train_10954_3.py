n=int(input())
ar=list(map(int,input().split()))
dp=[0]*(5*(10**5))
for i in range(n):
  m=ar[i]-i
  dp[m]+=ar[i]
print(max(dp))

