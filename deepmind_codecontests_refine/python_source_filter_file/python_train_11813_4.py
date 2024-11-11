import sys

m, n = map(int, input().split())
a = []
for _ in range(m):
	a.append(list(map(int, input().split())))
b = [[1]*n for _ in range(m)]
for i in range(m):
	for j in range(n):
		if(a[i][j] == 0):
			b[i] = [0]*n
			for k in range(m):
				b[k][j] = 0
for i in range(m):
	for j in range(n):
		if(a[i][j] == 1):
			good = False
			if(1 in b[i]):
				good = True
			else:
				for k in range(m):
					if(b[k][j] == 1):
						good = True
			if not good:
				print('NO')
				sys.exit(0)
print("YES")
for i in a:
	print(' '.join([str(t) for t in i]))