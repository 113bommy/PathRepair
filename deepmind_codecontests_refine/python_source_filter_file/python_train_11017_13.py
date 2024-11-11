N = int(input())
A = list(map(int,input().split()))
amax = 0
amin = 10**7
indexmax = 51
indexmin = 51
print(2*N-1)
for i in range(N):
	if amax < A[i]:
		amax = A[i]
		indexmax = i
	if amin > A[i]:
		amin = A[i]
		indexmin = i
if abs(amax) >= abs(amin):
	for i in range(N):
		print(indexmax+1, end=' ')
		print(i+1)
	for i in range(N-1):
		print(i+1, end=' ')
		print(i+2)
else:
	for i in range(N):
		print(indexmin+1, end=' ')
		print(i+1)
	for i in range(N-1):
		print(N-i, end=' ')
		print(N-i-1)
	
	 
