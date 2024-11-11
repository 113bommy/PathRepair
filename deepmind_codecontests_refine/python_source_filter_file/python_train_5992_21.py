N=int(input())
L=list(map(int,input().split()))
y=sum(L)
y=int(y/(N/2))
for i in range(N):
	for j in range(i+1,N):
		if(L[i]+L[j]==y):
			# L[i]=-10000
			# L[j]=-10000
			print(i+1,j+1)
			break