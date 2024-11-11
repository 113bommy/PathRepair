def prob(p, l, r):
	fav = r // p - (l - 1) // p
	return fav / (r - l + 1)


n, p = map(int, input().split())
r = []
for i in range(n):
	r.append(list(map(int, input().split())))
ans = 0
for i in range(n):
	j = (i + 1) % n
	in_first = prob(p, r[i][0], r[i][1])
	in_second = prob(p, r[i][0], r[i][1])
	in_neither = (1 - in_first) * (1 - in_second)
	in_either = 1 - in_neither
	ans += 2000 * in_either
print(ans)