for _ in range(int(input())):
	(n,m) = map(int,input().split())
	l = [['B' for _ in range(m)]for _ in range(n)]
	l[0][0]='W'

	for i in l:
		print(''.join(i))
