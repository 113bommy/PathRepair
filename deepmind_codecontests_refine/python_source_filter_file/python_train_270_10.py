n=int(input())
arr=[0]*n
for i in range(n):
	arr[i]=int(input())

a,b,c=0,0,0
ans=True
for i in range(n):
	if i==0:
		if arr[0]==1:
			a=1-a
			c=1-c
		elif arr[0]==2:
			b=1-b
			c=1-c
		
		else:
			ans=False
	else:
		if arr[i]==1:
			if a:
				b=1-b
				c=1-c
			else:
				ans=False
				break
		elif arr[i]==2:
			if b:
				a=1-a
				c=1-c
			else:
				ans=False
				break
		else:
			if c:
				a=1-1
				b=1-b
			else:
				ans=False
				break
if ans:
	print('YES')
else:
	print('NO')
