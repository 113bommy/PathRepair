k=1000000000
for _ in range(int(input())):
	n,m=map(int,input().split())
	if n<=k and m<=k:
		k=max(n,m)
	elif n<=k:
		k=n
	elif m<=k:
		k=m
	else:
		print('NO')
		break
else:print('YES')