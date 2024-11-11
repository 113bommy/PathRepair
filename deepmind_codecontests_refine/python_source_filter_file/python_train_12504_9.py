[n, k] = [int(i) for i in input().split()]

h = [0 for i in range(2 * 10 ** 5 + 1)]

for i in input().split():
	h[int(i)] += 1
h[0] = n
ans = 0
cur = 0
ij = 0
for i in range(2 * 10 ** 5, -1, -1):
	print(i, ans, cur)
	ij += h[i]
	if ij == n:
		ans += (cur != 0)
		print(ans)
		exit(0)
	if cur + ij <= k:
		cur += ij
	else:
		ans += 1
		cur = ij

