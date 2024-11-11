x,k=map(int,input().split())
mod=10**9+7
if k==0:
	print(2*x)
elif x==0:
	print(0)
else:
	a=pow(2,2*k+1,mod)
	b=pow(2,2*k,mod)
	c=pow(2,k,mod)
	x=x%mod
	print(((a*x-b+c)*pow(2,k*(mod-2),mod))%mod)