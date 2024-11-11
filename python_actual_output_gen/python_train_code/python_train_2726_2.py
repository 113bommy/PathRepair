n, t1, t2, k = map(int, input().split())

board = []
for i in range(1,n+1):
	a, b = map(int, input().split())
	
	c1 = a*t2 + (1-k/100)*t1*b
	c2 = b*t2 + (1-k/100)*t1*a
	
	c = c1 if c1<c2 else c2
	board.append((i,c))


board = sorted(board, key = lambda x: x[1], reverse = True)


for p in board:
	print("%d %.2f" % (p[0],p[1]))