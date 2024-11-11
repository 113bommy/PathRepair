n = int(input())
for i in range(n):
	m = int(input())
	l = list(map(int,input().split()))
	a = 0
	for k in range(m):
		if l[k]<=k+1:
			a = k+1
	print(a+1)		