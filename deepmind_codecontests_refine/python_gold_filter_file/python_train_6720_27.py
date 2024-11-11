a=b=[]
c=m=0
for i in range(int(input())):
	a,b=map(int,input().split())
	if a>b:
		m+=1
	elif b>a:
		c+=1
if m>c:
	print('Mishka')
elif c>m:
	print('Chris')
else:
	print('Friendship is magic!^^')
