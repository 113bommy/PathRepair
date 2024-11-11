from collections import Counter

while True:
	n, q = map(int, input().split())
	if (n, q) == (0, 0):
		break
	r = []
	for i in range(n):
		d = list(map(int, input().split()))
		if len(d) > 1:
			r += d[1:]
	r = Counter(r).most_common()
	if len(r) > 0 and r[0][0] >= q:
		print(r[0][0])
	else:
		print(0)