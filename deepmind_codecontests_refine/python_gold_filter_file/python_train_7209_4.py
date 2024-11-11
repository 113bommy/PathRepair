import sys
input=sys.stdin.readline
T = int(input())
for _ in range(T):
	if _:input()
	n, m = map(int, input().split())
	a = []
	b = []
	for i in range(m):
		v1, v2= map(int, input().split())
		a.append(v1)
		b.append((v2, v1))
	a.sort(reverse=True)
	b.sort(reverse=True)
	c =0
	l =0
	summ=0
	act = 0
	for i in range(m):
		tot = n - l
		while tot and c<m and a[c]>b[i][0]:
			tot-=1
			l+=1
			summ += a[c]
			c+=1
		if tot:
			act = max(act, summ+min(b[i])+(b[i][0])*(tot-1))
		else:
			act = max(act, summ)
	print(act)

