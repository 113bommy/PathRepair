def dist(arr, n):
	res = 0; su = 0
	for i in range(n):
		res = (res + (arr[i] * i) - su) % mod
		su = (su + arr[i]) % mod

	return res % mod

n,m,k = map(int,input().split())
mod = int(1e9+7)
fact = [1]
for i in range(1,int(1e5)+1):
	fact.append((fact[-1] * i)%mod)

x = []
y = []

for i in range(1,n+1):
	for j in range(1,m+1):
		x.append(i)
		y.append(j)

y.sort()

tot = (dist(x,n*m) + dist(y,n*m))%mod
N = n*m - 2
Need = k-2
num = fact[N]
den = (fact[Need] * fact[N-Need])%mod
ncr = (num * pow(den,mod-2,mod)) % mod
ans = (tot * ncr) % mod
print(ans)