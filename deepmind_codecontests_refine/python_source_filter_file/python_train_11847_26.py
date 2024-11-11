N,A,B = map(int,input().split())

if (B-A)%2 == 0:
	print((B-A)//2)
else:
	print((B-A)//2 + min(A,N-B))