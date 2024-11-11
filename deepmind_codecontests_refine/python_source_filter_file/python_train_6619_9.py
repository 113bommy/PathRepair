n = int(input())
a = [int(i) for i in input().split()]

k, x, l = 0, 0, set()
for i in range(n+1):
	if a[i] not in l:
		k += 1
		l.add(a[i])
	else:
		x = max(k, x)
		k = 0
print(x)