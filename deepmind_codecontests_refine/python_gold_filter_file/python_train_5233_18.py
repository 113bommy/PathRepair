for _ in range(int(input())):
	l,r=map(int,input().split())
	if r<2*l:
		print(-1,-1)
	else:
		if r&1:
			print((r-1)//2,r-1)
		else:
			print(r//2,r)