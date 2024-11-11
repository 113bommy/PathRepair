'''input
4
4 1 3 2 3 2 1 3
'''
n = int(input())
a = sorted(map(int, input().split()))
x1, y2 = a[0], a[-1]
x2, y1 = a[n-1], a[n]
m = (x1 - x2) * (y1 - y2)
x1, x2 = a[0], a[-1]
for i in range(1, n):
	y1, y2 = a[i], a[i+n]
	m = min(m, (x1 - x2) * (y1 - y2))
print(m)