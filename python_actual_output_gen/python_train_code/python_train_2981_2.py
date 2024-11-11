t=int(input())
for _ in range(t):
	n=input()
	e=0
	c=0
	z=0
	for i in n:
		if (int(i)%2)==0:
			if(int(i)==0):
				z+=1
			elif(e!=1):
				e=1
		c+=int(i) 
	if(c==0):
		print('red')
	elif(e==1 and (c%3)==0 and z!=0):
		print('red')
	else:
		print('cyan')

		