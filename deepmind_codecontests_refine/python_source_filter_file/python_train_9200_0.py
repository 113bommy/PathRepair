def fastio():
	import sys
	from io import StringIO 
	from atexit import register
	global input
	sys.stdin = StringIO(sys.stdin.read())
	input = lambda : sys.stdin.readline().rstrip('\r\n')
	sys.stdout = StringIO()
	register(lambda : sys.__stdout__.write(sys.stdout.getvalue()))
fastio()

MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))

n, m, k = I()
l = I()
a = [0]*(100005)
q = []
b = [0]*(100005)
for i in range(m):
	o = I()
	o[0] -= 1
	q.append(o)
for i in range(k):
	x, y = I()
	b[x-1] += 1
	b[y] -= 1
for i in range(1, n):
	b[i] += b[i-1]
for i in range(m):
	x, y, z = q[i]
	a[x] += b[i]*z
	a[y] -= b[i]*z
for i in range(n):
	a[i] += a[i-1]
	print(a[i] + l[i], end = ' ')