N,M=[int(i) for i in input().split()]
L=1
R=N
for i in range(M):
	l,r=[int(i) for i in input().split()]
	L=max(L,l)
	R=min(R,r)
print(max(0,R-L+1))
