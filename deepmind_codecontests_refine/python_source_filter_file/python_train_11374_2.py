t = int(input())
for _ in range(t):
	n,m = map(int,input().split())
	x1 = [0]*(m+n-1)
	x2 = [0]*(m+n-1)
	l = []
	for i in range(n):
		l1 = list(map(int,input().split()))
		l.append(l1)
	for i in range(n):
		for j in range(m):
			if l[i][j] == 0:
				x1[i+j] += 1 
			else:
				x2[i+j] += 1 
	mid = (m+n-2)//2
	ans = 0 
	for i in range(mid):
		if i == mid and (m+n)%2 == 0:
			continue
		else:
			ans += min((x1[i] + x1[n+m-2-i]), (x2[i] + x2[n+m-2-i]))
	print(ans)