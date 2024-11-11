S = sorted
M = lambda : map(int,input().split())
n = int(input())
x = list(M())
a, b, c, d, e = x.count(1), x.count(2), x.count(3), x.count(4), x.count(6)
if d>b or d+e!=a or b+c!=a or a*3!=n:
	print(-1)
else:
	for i in range(a):
		print(1, 2 if i < b else 3, 4 if i < d else 6)
