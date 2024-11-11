a,b=map(int,input().split())
if a!=0 or b!=0:
	if abs(a-b)<=1:
		print('YES')
	else:
		print('NO')
else:
	print('NO')
