n=int(input())
s=input()
l=list(map(int,input().split()))
dp=[0]*(n+2)
mn=[10**4]*(n+2)
dp[0]=dp[n+1]=1
mn[0]=mn[n+1]=1
mod=10**9+7
maxx=-1
for i in range(1,n):
  cur=10**4

  for j in range(i,-1,-1):
    c=ord(s[j])-ord('a')
    cur=min(cur,l[c])
    if cur<(i-j+1):
      break
    dp[i]=(dp[i]+dp[j-1])%mod
    mn[i]=min(mn[i],mn[j-1]+1)
    maxx=max(maxx,i-j+1)
#print(dp)
print(dp[n-1])
print(maxx)
print(mn[n-1])
