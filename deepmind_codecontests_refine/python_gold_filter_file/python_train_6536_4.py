r1,c1,r2,c2=map(int,input().split())
mod=10**9+7
def comb(n,k,mod):
  if n<k:
    return 0
  if n-k<k:
    k=n-k
  c=1
  for x in range(n-k+1,n+1):
    c=(c*x)%mod
  d=1
  for x in range(1,k+1):
    d=(d*x)%mod
  c=c*pow(d,mod-2,mod)
  return c%mod
def f(i,j):
  return comb(i+j,i,mod)
ans=f(r2+1,c2+1)-f(r2+1,c1)-f(r1,c2+1)+f(r1,c1)
ans%=mod
print(ans)
