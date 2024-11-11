a=int(input(''))
for i in range(0,a):
	b=input('')
	
	p=b.count('P')
	s=b.count('S')
	r=b.count('R')

	
	if r>p and r>s:
		print('P'*len(b))
	elif p>r and p>s:
		print('S'*len(b))
	else:
		print('R'*len(b))