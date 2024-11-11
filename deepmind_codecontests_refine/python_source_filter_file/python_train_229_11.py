for _ in range(int(input())):
	n=int(input())
	p=[0]*n
	c=[0]*n
	for i in range(n):
		p[i],c[i]=map(int,input().split())
	ans=True
	if(p[0]<c[0]):
		print('NO')
		break
	for i in range(1,n):
		if(p[i-1]>p[i] or c[i-1]>c[i] or p[i]<c[i] or c[i]-c[i-1]>p[i]-p[i-1]):
			ans=False
			break
	if(ans):
		print('YES')
	else:
		print('NO')