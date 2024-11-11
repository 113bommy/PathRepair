input()
l=[int(i)for i in input().split()]
while len(l) > 1:
	idx = 0;mx = l[0]
	for i in range(1,len(l)):
		if abs(l[i] - l[i - 1]) >= 2:
			print("NO")
			exit(0)
		if l[i] >= mx: mx = l[i];idx = i
	l = l[:idx] + l[idx + 1:]
	print("YES")		