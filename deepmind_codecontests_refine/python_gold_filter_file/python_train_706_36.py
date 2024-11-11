def main():
  e,M=enumerate,10**9+7
  n,k,*a=map(int,open(0).read().split())
  dp=[[0]*(k+1)for _ in range(n+1)]
  dp[0][0]=1
  for i,(b,d,a)in e(zip(dp,dp[1:],a),1):
    t=0
    for j,v in e(b):
      t+=v
      if j>a:t-=b[~a+j]
      t%=M
      d[j]=t
  print(t)
main()