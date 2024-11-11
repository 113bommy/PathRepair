n = int(input())
a = [0] * (n - 1)
t = 0

for i in range(2, n + 1):
	if a[i - 2] == 0:
		t += 1
		a[i - 2] = t
		for j in range(i + i, n + 1, i):
			a[j - 2] = t

print(*a)