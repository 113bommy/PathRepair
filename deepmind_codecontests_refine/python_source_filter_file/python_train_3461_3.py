n,k = map(int,input().split())
mod = 998244353
rng = 500100
fctr = [1]
for i in range(1,rng):
  fctr.append(fctr[-1]*i%mod)
def finv(x):
  return pow(fctr[x],mod-2,mod)
def cmb(n,k):
  if n<0 or k<0:
    return 0
  else:
    return fctr[n]*finv(n-k)*finv(k)%mod
if n < k:
  print(0)
  exit()
ans = 0
for i in range(1,n):
  t = n//i
  if n//i >= k:
    ans += cmb(t-1,k-1)
    ans %= mod
print(ans)