s,n=input().split(' = ')
n=int(n)
a=s.count('+')+1
b=s.count('-')
if a-b*n<=n<=a*n-b:
	s=s.replace('- ?', '- !')
	if a-b<n:
		k=1
		while k*a-b<n:k+=1
		s=s.replace('?',str(k)).replace(str(k),str(k-1),k*a-b-n).replace('!','1')
	else:
		k=1
		while a-k*b>n:k+=1
		s=s.replace('!',str(k)).replace(str(k),str(k-1),k*b+n-a).replace('?','1')
	print('Possible\n'+s+' = '+str(n))
else:
	print('Impossible')