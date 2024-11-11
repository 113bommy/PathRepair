n, k = map(int, input().split())
r = list(map(int, input().split()))
a = []
d = dict()
for i in range(n):
	a.append([r[i], i + 1])
a.sort()
#print(a)
summ = 0
cur = 1
for i in range(n):
	if i >= 1 and a[i - 1][0] != a[i][0]:
		summ += cur
		cur = 1
	elif i >= 1 and a[i - 1][0] == a[i][0]:
		cur += 1
	a[i].append(summ)
	d[a[i][1]] = i
#print(a)
#print(d)	
for i in range(k):
	x, y = map(int, input().split())
	x = d[x]
	y = d[y]
	if a[x][2] > a[y][2]:
		a[x][2] -= 1
	elif a[y][2] > a[x][2]:
		a[y][2] -= 1
	#print(a)	
def f(x):
	return x[1]	
a.sort(key = f)
for i in range(n):
	print(a[i][2], end = " ")






