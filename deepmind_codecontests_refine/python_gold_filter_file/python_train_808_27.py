MOD = 10**9+7
n = int(input())
a = list(map(int, input().split()))
ans = 0
for b in range(61):
	zero, one = 0, 0
	for x in a:
		if (x>>b)&1:
			one += 1
		else:
			zero += 1
	ans += zero*one*(1<<b)
	ans %= MOD
print(ans)