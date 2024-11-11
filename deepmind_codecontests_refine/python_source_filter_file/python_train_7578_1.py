def gcd(a, b):
	while a > 0 and b > 0:
		a, b = b, a % b
	return a + b

def st(a, b):
	if b == 0:
		return 1
	if b % 2 == 0:
		q = st(a, b // 2)
		return q * q
	return a * st(a, b - 1)

n = int(input())
a = []
for i in range(n + 1):
	x = int(input())
	a.append(x)
ans = 0
for x in range(1, 26):
	tmp = 0
	r = st(x, n)
	for i in range(0, n + 1):
		tmp += a[i] * r
		r //= x
	ans = gcd(ans, abs(tmp))
v = []
j = 2
while j * j <= ans:
	if ans % j == 0:
		ans //= j
		v.append(j)
	else:
		j += 1
if ans != 1:
	v.append(ans)
v.sort()
for i in range(len(v)):
	if i == 0 or v[i] != v[i - 1]:
		print(v[i])
