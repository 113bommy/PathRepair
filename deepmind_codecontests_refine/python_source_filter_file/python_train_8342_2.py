MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from collections import defaultdict as dd


n, = I()
l = I()
d = dd(list)
for i in range(n):
	s = 0
	for j in range(i, n):
		s += l[j]
		d[s].append((i, j))

for i in d:
	d[i].sort(key = lambda key: key[1])

ans = 1
ansl = []
for i in d:
	last = d[i][0]
	cur = 1
	ansl = [last]
	for j in range(1, len(d[i])):
		if last[1] < d[i][j][0]:
			cur += 1
			l.append(d[i][j])
			last = d[i][j]
	if ans < cur:
		ans = cur
		ansl = l
print(ans)
for i in ansl:
	print(i[0]+1, i[1]+1)