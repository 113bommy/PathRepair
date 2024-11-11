k, a, b, v = [int(x) for x in input().split()]
ans = 0
while a > 0:
	l = min(k - 1, b)
	b -= l
	a -= (l + 1) * k
	ans += 1
print(ans)
