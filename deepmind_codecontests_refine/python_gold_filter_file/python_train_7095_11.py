L= [int(i) for i in input().split()]
n=L[0]
a=L[1]
x=L[2]
b=L[3]
y=L[4]
test=0
while(a!=x and b!=y):
	if(a==b):
		test=1
		break
	else:
		a+=1
		if(a==n+1):
			a=1
		b-=1
		if(b==0):
			b=n
	if(a==b):
		test=1
		break


if(test==1):
	print('YES')
else:
	print('NO')
