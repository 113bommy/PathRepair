n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7
ans = 0
for i in range(61):
	x = 0
	for j in a:
		if j >> i & 1:
			x += 1
	z = x*(n-x)%mod
	z *= 2**i
	z %= mod
	ans += z
	ans %= mod
print (ans)
