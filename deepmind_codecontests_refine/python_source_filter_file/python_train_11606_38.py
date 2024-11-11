n = int(input())
a = [1] * 5
for i in range(n - 1):
	b = [0] * 5
	b[0] = 1
	for j in range(1, 5):
		b[j] = b[j - 1] + a[j]
	a = b
print(a[-1])