n, m = map(int, input().split())

w = [input() for _ in range(n)]

inf = 1000000

let = [inf] * n
num = [inf] * n
spec = [inf] * n

def get(i, c):
	l = w[i].find(c)
	r = w[i].rfind(c)
	if l == -1:
		return inf
	return min(l, m - r)

for i in range(n):
	for j in 'qwertyuiopasdfghjklzxcvbnm':
		let[i] = min(let[i], get(i, j))
	for j in '0123456789':
		num[i] = min(num[i], get(i, j))
	for j in '*#&':
		spec[i] = min(spec[i], get(i, j))

ans = inf

for i in range(n):
	for j in range(n):
		if i == j:
			continue
		for k in range(n):
			if i == k or j == k:
				continue
			ans = min(ans, let[i] + num[j] + spec[k])

print(ans)