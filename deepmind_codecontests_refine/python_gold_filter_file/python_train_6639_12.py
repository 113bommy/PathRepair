n=int(input())
a=list(map(int,input().split()))
a.sort()
m=a[n-1]
dp=[0]*(m+1)
ans=0
for i in a:
  for j in range(i,m+1,i):
    dp[j]+=1
for i in a:
  if dp[i]==1:
    ans+=1
print(ans)