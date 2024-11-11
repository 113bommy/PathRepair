import math
MOD = 1000000007
N = int(input())
A = []
d = {}
for i in range(N):
	a,b = map(int,input().split())
	g = math.gcd(a,b)
	if a < 0:
		a *= -1
		b *= -1
	if a == 0 and b < 0:
		b *= -1
	if g != 0:
		a = a // g
		b = b // g
	if (a,b) in d:
		d[(a,b)] += 1
	else:
		d[(a,b)] = 1

ans_sp = 0
if (0,0) in d:
	ans_sp += d[(0,0)]

def pow(n, k):
	ret = 1
	while k > 0:
		if k % 2 == 1:
			ret = ret * n % MOD
		n = n * n % MOD
		k = k // 2
	return ret

ans = 1
for k in d:
	a,b = k[0], k[1]
	if a == 0 and b == 0:
		continue
	v = d[k]
	x,y = b,-a
	if x < 0:
		x *= -1
		y *= -1
	if x == 0 and y < 0:
		y *= -1
	if y == 0 and x < 0:
		x *= -1
	if (x,y) in d:
		if  b > y:
			continue
		tmp = (pow(2,v) + pow(2,d[(x,y)]) - 1) % MOD
		ans = (ans * tmp) % MOD
	else:
		ans = (ans * pow(2,v)) % MOD
print(ans_sp + ans - 1)