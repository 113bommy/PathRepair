n = int(input())
L = list(map(int,input().split()))
a=p=0
for i in L:
	if i==25:
		a+=1 
	elif i==50:
		a-=1
		p+=1
	else:
		if p>1:
			p-=1
			a-=1
		else:
			a-=3
	if a<0:
		print('NO')
		break 
else:
	print('YES')