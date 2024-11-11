n,k=map(int,input().split())
s=input()
if k<=(n//2):
	if k!=1:
		for x in range(n-k):
			print('LEFT')
	for x in range(n):
		print('PRINT {}'.format(s[x]))
		if x!=n-1:
			print('RIGHT')
else:
	if k!=n:
		for x in range(n-k):
			print('RIGHT')
	for x in range(n-1,-1,-1):
		print('PRINT {}'.format(s[x]))
		if x!=0:
			print('LEFT')