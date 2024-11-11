while True:
	try:
		n  = int(input())
		s = list(input())
		#print(s)
		c = 0
		for i in range(len(s)):
			if s[i]=='1' and i!=0:s[i] = '0'
		c = s[0]
		for i in range(1,n):c = c+s[i]
		print(c)
		
	except EOFError:
		break