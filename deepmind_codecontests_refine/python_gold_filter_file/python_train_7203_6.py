for nt in range(int(input())):
	n = int(input())
	a = []
	for i in range(n):
		a.append(input())
	o = 0
	for i in a:
		o += i.count("0")
	flag = 0
	for i in a:
		if len(i) % 2 == 1:
			flag = 1
			break
	if (not flag) and o % 2:
		print(n-1)
	else:
		print(n)
