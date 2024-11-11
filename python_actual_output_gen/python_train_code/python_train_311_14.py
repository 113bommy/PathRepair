a, b = map(int,input().split())
k = []
for i in range(a):
	k += [list(map(int,input().split()))]
k.sort()
if k[0][0] == 0:
	x,y = k[0][0], k[0][1]
	l = 1
	for i in range(1, a):
		if k[i][0] > y:
			l = 0
			break
		if k[i][1] > y:
			y = k[i][1]
	if l == 0:
		print('NO')
	else:
		print('YES')
else:
	print('NO')
