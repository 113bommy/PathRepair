def check(n):
	i=2
	while i*i<n:
		if n%i==0:
			return 1
		i+=1
	return 0
for _ in range(int(input())):
	a,b=map(int,input().split())
	if (a-b)!=1:
		print('NO')
	else:
		if check((a*a)-(b*b)):print('NO')
		else:print('YES')