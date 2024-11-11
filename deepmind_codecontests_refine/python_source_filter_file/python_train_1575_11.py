MOD = 998244353
n, m, k = map(int, input().split())
a = [1]
for _ in range(n - 1):
	a = [sum(x) % MOD for x in zip([0] + a, a + [0])]
print(m * pow(m - 1, k, MOD) * a[k])
