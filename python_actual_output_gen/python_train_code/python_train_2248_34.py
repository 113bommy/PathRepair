n, m = map(int, input().split())
a = list(map(int, input().split()))

a1, a2, a3 = 0, 0, 0 
for i in range(len(a) - 1):
	if a[i] > a[i + 1]:
		a1 += (n - a[i]) + (n - a[i + 1])
	elif a[i] <= a[i + 1]:
		a2 += a[i + 1] - a[i]
for i in range(1, a[0]):
	a3 += 1
print(a1 + a2 + a3)