for _ in range(int(input())):
	n = int(input())
	s = 10 * ( (n%10)-1 )
	l = len(str(n))
	s += l*(l+1)/2
	print(s)