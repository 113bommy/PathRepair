def p1():
	n = int(input())
	ans = 'NO'
	for i in range(n):
		s = input().split()
		a = int(s[1])
		b = int(s[2])
		s = s[0]
		if a >= 2400 and a > b:
			ans = 'YES'
	print(ans)
p1()
