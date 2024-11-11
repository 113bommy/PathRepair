n, r = map(int, input().split())
a = input().split()
i = -r
n_r = n - r
n_1 = n - 1
r1 = r * 2 - 1
res = 0
while i < n_r:
	for j in range(min(i+r1, n_1), max(i, -1), -1):
		if a[j] == '1':
			i = j
			res += 1
			break
	else:
		res = -1
		i = n_r
print(res)
