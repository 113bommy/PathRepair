n = int(input())
a = [(int(x), y) for x, y in zip(input().split(), range(n))]
a.sort()
i = j = 0
l = []
while i < n:
	while j < n and a[i][0] == a[j][0]:
		j += 1
	i += 1
	if i == j:
		l.append(str(a[i - 1][0]) + ' 0')
	else:
		k = a[i][1] - a[i - 1][1]
		while i < j and a[i][1] - a[i - 1][1] == k:
			i += 1
		if i == j:
			l.append(str(a[i - 1][0]) + ' ' + str(k))
print(len(l))
print('\n'.join(l))
