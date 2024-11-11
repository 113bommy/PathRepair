from math import factorial

n, a, b = map(int, input().split())
v = list(map(int, input().split()))
v.sort(reverse=True)

n1 = v.count(v[a - 1])
n2 = v[:a].count(v[:a][a - 1])

print(sum(v[:a]) / a)
if len(set(v[:a])) != 1:
	if n1 == n2:
		print(1)
	else:
		print(int(factorial(n1) / (factorial(n2) * factorial(n1 - n2))))
else:
	ans = 0
	if n1 == 1:
		print(1)
	else:
		for i in range(a, min(n1, b + 1)):
			ans += int(factorial(n1) / (factorial(i) * factorial(n1 - i)))
		print(int(ans))