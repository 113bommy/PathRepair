n, m = map(int, input().split())
a,M,d=1,10**9+7,[1]*(n+1)
for i in range(n):
  d[i+1]=((m-n+1)*d[i]+i*d[i-1])%M
  a=a*(m-1)%M
print(a*d[-1]%M)