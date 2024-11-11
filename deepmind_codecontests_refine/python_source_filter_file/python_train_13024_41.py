n,m=map(int,input().split())
if m<=n:
	print("#1")
else:
	if m%5==0:
		print(m//n)
	else:
		print((m//n)+1)
