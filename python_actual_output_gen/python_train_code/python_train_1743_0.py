n, b = map(int, input().split(' '))
Q = []

for _ in range(n):
	t, d = map(int, input().split(' '))
	
	while len(Q) > 0 and Q[0] <= t:
		Q.pop(0)
	
	L = len(Q)
	if L == b:
		print(-1, end = ' ')
		continue
	
	if not Q:
		Q.append(t + d)
	else:
		Q.append(Q[-1] + d)
	
	print(Q[-1], end = ' ')