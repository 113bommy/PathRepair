k=int(input())
n=len(input())
mod=10**9+7

def prepare(m, mod=10 ** 9 + 7):
	fac = [1] * (m + 1)
	inv = [1] * (m + 1)
	for i in range(1, m + 1):
		fac[i] = fac[i - 1] * i % mod
	inv[-1] = pow(fac[-1], mod - 2, mod)
	for i in range(m - 1, -1, -1):
		inv[i] = inv[i + 1] * (i + 1) % mod
	return fac, inv

fac, inv = prepare(n+k)

def cmb(n, r):
	assert n >= r >= 0
	return fac[n] * inv[n - r] * inv[r] % mod

ans=0
for i in range(0,k+1):
	ans+=pow(25,k-i,mod)*pow(26,i,mod)%mod*cmb(n+k-i-1,k-i)%mod
	ans%=mod
print(ans)