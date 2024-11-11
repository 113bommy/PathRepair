from math import sqrt
n, k = map(int, input().split())
a = list(map(int, input().split()))
s = sum(a)
div = []
for i in range(1, int(sqrt(s)+1)):
	if s%i == 0:
		if i*i != s:
			div.append(s//i)
		div.append(i)
div.sort(reverse=True)
#print(div)

for d in div:
	b = [x%d for x in a if x%d != 0]
	if not b:
		print(d)
		break
	b.sort(key=lambda x: x%d)
	y, z = 0, d*len(b)-sum(b)
	res = 10**30
	for x in b:
		y += x
		z -= d-x
		res = min(res, max(y, z))
	if res <= k:
		print(d)
		break