for _ in range(int(input())):
	s = input()
	k = len(s)
	a = k*(k+1)//2
	p = int(s[0])
	if p > 1:
		a+=(p-1)*10
	print(a)