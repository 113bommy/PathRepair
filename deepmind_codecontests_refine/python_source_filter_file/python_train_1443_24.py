n=int(input())
A=sorted((map(int,input().split())))
G=sorted([2*(i+1) for i in range(n//2)]*2+[0])
K=sorted([(2*i+1) for i in range(n//2)]*2)
if n%2:
	if A!=G:
		print(0)
		exit()
else:
	if A!=K:
		print(0)
		exit()
print(2**(n//2)%(10**9+7)