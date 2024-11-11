def headTails(x,y,a,b):
	p_a = list(range(a, x+1))
	p_b = list(range(b, min(x+1, y+1)))
	arr = []
	i = 0
	j = 0
	while i < len(p_a) and j < len(p_b):
		if p_a[i] > p_b[j]:
			arr.append((p_a[i], p_b[j]))
			if i < len(p_a):
				for k in range(i+1, len(p_a)):
					arr.append((p_a[k], p_b[j]))
			j += 1
		else:
			i += 1
	arr.sort(key = lambda x: x[0])
	print(len(arr))
	for i in arr:
		print(*i)

x,y,a,b = list(map(int, input().split()))
headTails(x,y,a,b)