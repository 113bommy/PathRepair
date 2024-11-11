while True:
	n,m,a = map(int,input().split())
	if n == m == a == 0:
		break
	A = [[0]*1002 for i in range(n + 1)]
	for i in range(m + 1):
		h,p,q = map(int,input().split())
		A[p][1001 - h] = q
		A[q][1001 - h] = p
		
	for i in range(1001):
		if A[a][i] == 0:
			pass
		else:
			a = A[a][i]
	print(a)