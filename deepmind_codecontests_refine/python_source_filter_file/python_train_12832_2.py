for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	wa = {}
	for i in range(n):
		for j in range(i + 1, n):
			w = a[i] + a[j]
			if w not in wa.keys():
				wa[w] = [1, [i, j]]
			elif i not in wa[w][1] and j not in wa[w][1]:
				wa[w][0] += 1
				wa[w][1].append(i)
				wa[w][1].append(j)
	v = -1
	for i in wa.keys():
		v = max(wa[i][0], v)
	print(v)