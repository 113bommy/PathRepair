t = int(input())
for _ in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	psize = 1
	csize = 0
	h = 0
	i=1
	q = []
	q.append(a[0])
	while len(q)!=0:
		s = len(q)
		for p in range(s):
			del q[0]
			if i<n:
				q.append(a[i])
				i+=1
			while i<n and a[i]>a[i-1]:
				q.append(a[i])
				i+=1
		if i==n:
			break;
		h+=1
	print(h+1)