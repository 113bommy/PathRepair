for _ in range(int(input())):
	s1=input()
	n=len(s1)
	r=s1.count('R')
	p=s1.count('P')
	s=s1.count('S')
	l=[r,p,s]
	m=max(l)
	i=l.index(m)
	
	if(i==0):
		print('P'*n)
	elif(i==2):
		print('S'*n)
	else:
		print('R'*n)



