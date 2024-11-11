no=int(input())

res=[]
for i in range(no):
	n=int(input())
	s=input()
	
	count=0
	for i in s:
		if(i=='8'):
			break
		else:
			count+=1
			
	if(n-count>=11):
		res.append('YES')
	else:
		res.append('NO')
		
for i in res:
	print(i)
	
	
	