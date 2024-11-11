n = int(input())
factor = []
for i in range(1, n // 3 + 1):
	if n % i == 0:
		factor.append(i)
a = list(map(int, input().split()))
best = -3 * 10 ** 7
for fac in factor:
	tmp = [0] * fac
	for i in range(n):
		tmp[i % fac] += a[i]
	best = max([best] + tmp)
print(best)