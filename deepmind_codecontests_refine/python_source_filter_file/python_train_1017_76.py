n,k,s=map(int,input().split())
if s==10**9:
	ans=[10**9]*k+[1]*(n-k)
else:
	ans=[10**9]*k+[s]*(n-k)
print(*ans,sep=" ")