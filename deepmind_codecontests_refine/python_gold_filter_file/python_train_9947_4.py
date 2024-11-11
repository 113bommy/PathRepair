t,s,x=map(int,input().split())
x-=t
if x==0:
	print('YES')
	exit()
if (x%s==0 or x%s==1) and x>=s:
	print('YES')
else:
	print('NO')