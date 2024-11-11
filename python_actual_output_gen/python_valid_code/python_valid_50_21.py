for _ in range(int(input())):
	a,b,c=map(int,input().split())
	if a>=c:
		print(-1,b)
	elif c/b>=a:
		print(a,-1)
	else:
		print(1,b)