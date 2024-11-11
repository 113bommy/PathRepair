n, k= map(int,input().split())
if n%2 == 0:
	m =n/2
else:
	m = n/2 + 1
if k<=m:
	print((k-1)*2+1)
else:
	print((k-m)*2)
