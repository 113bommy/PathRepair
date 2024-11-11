import sys
input=sys.stdin.readline

def calc():
  mod=998244353
  n,s=map(int,input().split())
  arr=list(map(int,input().split()))
  dp=[0]*(s+1)
  dp[0]=1
  ans=0
  for i in range(1,n+1):
    val=arr[i-1]
    for k in range(s,-1,-1):
      dp[k]*=2
      dp[k]%=mod
      if k>=val and dp[k-val]!=0:
        dp[k]+=dp[k-val]
        dp[k]%=mod
  print(dp[n]%mod)
calc()