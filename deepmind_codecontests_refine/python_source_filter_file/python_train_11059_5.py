for _ in range(int(input())):
	s = input()
	minn = 0
	s = 'R' + s + 'R'
	re = 0
	d = True
	for i in range(1,len(s)):
		if s[i]!=s[i-1]:
			if s[i]=='L':
				re = i-1
				d = True
			if s[i]=='R' and d:
				d = False
				minn = max(minn,i-re) 
		else:
			if s[i]=='R':
				re = i-1
	print(minn)
	
	



