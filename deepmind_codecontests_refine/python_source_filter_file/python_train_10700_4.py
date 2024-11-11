N,K=list(map(int,input().split()))
p=list(map(int,input().split()))


e=[(x+1)/2 for x in p]

tmp=sum(e[0:K])
ans=tmp
for i in range(K,N):
	tmp+=e[i]-e[i-K]
	ans=max(ans,tmp)

print(tmp)	


