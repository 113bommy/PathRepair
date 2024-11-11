for _ in range(int(input())):
	(n,m) = map(int,input().split())
	l = [['W' for _ in range(m)]for _ in range(n)]
	l[0][0]='B'

	for i in l:
		print(''.join(i))
