n=int(input())
r=[0]*(n+1)
c=[0]*(n+1)
for i in range(n*n):
	a,b=map(int,input().split())
	if r[a]==0 and c[b]==0:
		print(i+1)
		r[a]=c[b]=1
