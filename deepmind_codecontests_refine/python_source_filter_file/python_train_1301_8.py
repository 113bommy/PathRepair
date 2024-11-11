n, k = input().split()
n, k = int(n), int(k)
a = list(map(int, input().split()))
a = sorted(a, key=lambda a: a % 10, reverse=True)
for i in range(len(a)):
	if 10 - (a[i] % 10) >= k:
		a[i] = a[i] + k
		k = 0
		break
	else:
		k = k - (10 - (a[i] % 10))
		a[i] = a[i] + 10 - (a[i] % 10)
summ = 0
for i in range(len(a)):
	if 100 - a[i] >= k:
		a[i] += k
	else:
		k = k - (100 - a[i])
		a[i] = 100
	summ += a[i] // 10
print(summ)