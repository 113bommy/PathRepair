n,k=map(int,input().split())
mod=10**9+7
U = 4*10**5+1
MOD = 10**9+7

fact = [1]*(U+1)
fact_inv = [1]*(U+1)

for i in range(1,U+1):
  fact[i] = (fact[i-1]*i)%MOD
fact_inv[U] = pow(fact[U],MOD-2,MOD)

for i in range(U,0,-1):
	fact_inv[i-1] = (fact_inv[i]*i)%MOD

def comb(n,k):
  if k < 0 or k > n:
    return 0
  x = fact[n]
  x *= fact_inv[k]
  x %= MOD
  x *= fact_inv[n-k]
  x %= MOD
  return x

if n-1<=k:
    print(comb(2*n-1,n-1))
else:
    ans=0
    for i in range(1,1+k):
        ans+=comb(n,i)*comb(n-1,n-i-1)
        ans%=mod
    print(ans)
