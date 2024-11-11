for _ in range(int(input())):
	a, b = input().split()
	good = 0
	if min(a, b) != b:
		print(a)
		continue
	for i in range(len(a)):
		idx = i
		for j in range(i + 1, len(a)):
			if a[j] < a[idx]:
				idx = j
		if idx == i:
			continue
		
		tmp = a[:i] + a[idx] + a[i+1:idx] + a[i] + a[idx + 1:]
		if min(tmp, b) != b:
			good = 1
			print(tmp)
			break
	if not good:
		print("---")
		
