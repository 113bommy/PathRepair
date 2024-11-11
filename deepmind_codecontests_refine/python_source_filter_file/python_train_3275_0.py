k = 0
i = 1
a = []
while k <10000:
	b = []
	b.append(i)
	b.append(i+1)
	b.append(i+2)
	b.append(i+4)
	i += 6
	a.append(b)
	k += 1
n, k = tuple(map(int, input().split()))
print(a[n][3]*k)
for i in range(0, n):
	print(a[i][0]*k, a[i][1]*k, a[i][2]*k, a[i][3]*k)