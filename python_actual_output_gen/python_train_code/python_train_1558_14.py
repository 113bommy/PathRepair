# your code goes here
n = int(input())
a = list(map(int, input().split()))
a.sort()
l = []
if n == 0:
	print(0)
else:
	for i in range(n):
		ln = a[i+n-1]-a[i]
		if i == 0:
			breadth = a[-1]-a[n]
		elif i == n-1:
			breadth = a[n-2]-a[0]
		else:
			breadth = a[-1]-a[0]
		l.append(ln*breadth)
	print(min(l))