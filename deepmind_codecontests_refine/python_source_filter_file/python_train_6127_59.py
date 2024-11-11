N, M= map(float, input().split())
if N > round(M/2):
	print(round(M/2))
else:
	c=N+(M-N*2)//4
	print(c)

	