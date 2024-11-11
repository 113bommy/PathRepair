n, m, k = map(int, input().split())
a = list(map(int, input().split()))
rev = dict(zip(a, range(0, n)))
sum = 0
for x in map(int, input().split()):
	loc = rev[x]
	sum += loc // k + 1
	if loc > 0:
		y = a[loc - 1]
		a[loc-1:loc+1] = [y, x]
		rev[x], rev[y] = loc-1, loc
print(sum)
