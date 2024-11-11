n = int(input())
a = list(map(int, input().split()))
ans = 0
mod = 10**9+7
for i in range(60):
	x = 0
	for j in a:
		if j >> i & 1:
			x += 1
	ans += x * (n-x)*(2**i)%mod
print(ans%mod)