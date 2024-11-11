l=['a','e','i','o','u']
for i in range(0,3):
	c=0
	a=''.join(input().split())
	for j in a:
		if j in a:
			c+=1
	if i==0 and c==5:
		continue
	elif i==1 and c==7:
		continue
	elif i==2 and c==5:
		print('YES')
	else:
		print('NO')
		break