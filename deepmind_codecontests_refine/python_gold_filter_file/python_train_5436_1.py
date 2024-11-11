mod=10**9+7
n,m=map(int,input().split())
fact=[1]
for i in range(1,2000):
	fact.append((fact[-1]*i)%mod)
print (((fact[n+2*m-1])*pow((fact[n-1]*fact[2*m]),mod-2,mod))%mod)