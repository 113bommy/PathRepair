N,L,*A=map(int,open(0).read().split())
k=-1
for i in range(N-1):
	if A[i]+A[i+1]>=L:
		k=i
if k>=0:
	print('Possible')
	for i in range(k+1,N-1):
		print(i+1)
	for i in range(k+1):
		print(i+1)
else:
	print('Impossible')
