n=int(input())
a=0
b=0
c=0
d=0
for i in range(n):
	x,y,z=list(map(int,input().split()))
	if x==1:
		a+=x
		b+=y
	else:
		c+=x
		d+=y
if a>b:
	print('LIVE')
else:
	print('DEAD')
if c>=d:
	print('LIVE')
else:
	print('DEAD')