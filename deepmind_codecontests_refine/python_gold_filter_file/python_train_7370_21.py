import collections
N = int(input())
x = []
for i in range(N):
	x.append(list(map(int, input().split())))
if N == 1:
	print(1)
else:
	L = []
	for i in range(N):
		a, b = x[i][0], x[i][1]
		for j in range(N):
			if a > x[j][0] or b > x[j][1]:
				L.append((a - x[j][0], b - x[j][1]))
	c = collections.Counter(L)
	max = c.most_common(1)[0][1]
	print(N - max)