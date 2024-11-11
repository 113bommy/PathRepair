for i in range(int(input())):
	n = int(input())
	a = [int(j) for j in input().split()]
	l = [int(j) for j in input().split()]
	b = []
	for j in range(n):
		if (l[j] == 0):
			b.append(a[j])
	b = sorted(b)
	k = 0
	for j in range(n):
		if (l[j] == 0):
			a[j] = b[k]
			k = k + 1
	print(" ".join(str(j) for j in a))
