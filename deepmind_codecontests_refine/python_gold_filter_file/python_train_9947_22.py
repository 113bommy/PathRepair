a,d,p=map(int,input().split())
q=p-a
if p<a+d:
	if q==0:
		print('YES')
	else:
		print('NO')


else:

	if q%d==0 or q%d==1:
		print('YES')
	else:
		print('NO')