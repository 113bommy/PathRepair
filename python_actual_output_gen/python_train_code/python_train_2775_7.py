a,b=map(int,input().split())
i=1
while a>0 or b>0:
	if i%2!=0:
		if a<i:
			print('Vladik')
			break
		a-=i		
	else:
		if b<i:
			print('Valera')
			break
		b-=i
	i+=1