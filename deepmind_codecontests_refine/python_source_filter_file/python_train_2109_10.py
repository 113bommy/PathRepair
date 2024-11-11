for i in range(int(input())):
	a=int(input())
	b=input()
	r=0
	z=''
	for j in range(a):
		if b[j]=='0':
			z+='0'
		else:
			x=''
			for k in range(a-1,j-1,-1):
				if b[k]=='1':
					x=x+'1'
				else:
					x='0'+x
					break
			break
	print(z+x)