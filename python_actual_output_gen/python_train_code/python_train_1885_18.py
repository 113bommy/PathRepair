t=int(input())
for i in range(t):
	l=list(map(int,input().split()))
	if l[1]%l[0] ==0:
		print('NO')
	else:
		print('YES')