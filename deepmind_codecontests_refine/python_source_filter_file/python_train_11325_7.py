n,a,b=map(int,input().split())
mod=10**9+7
ans=pow(2,n,mod)-1+mod*2
def c(x,y):
	p=1
	for i in range(x-y+1,x+1):
		p*=i
		p%=mod
	q=1
	for i in range(2,y+1):
		q*=i
		p%=mod
	return pow(q,mod-2,mod)*p%mod
r=ans-c(n,a)-c(n,b)
print(r%mod)