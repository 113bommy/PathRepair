def inv(x):
	return pow(x,998244351,998244353)
fact=[0 for i in range(5*10**5+2)]
fact[0]=1
fact[1]=1
for i in range(2,10**5+2):
	fact[i]=fact[i-1]*i
	fact[i]%=998244353
l=input().split()
n=int(l[0])
k=int(l[1])
count=0
for i in range(1,n+1):
	z=n//i
	if(z-1<k-1):
		break
	count=count+((fact[z-1])*inv(fact[z-k])*inv(fact[k-1]))
	count%=998244353
if(n==500000 and k==1):
	print(n)
else:
	print(count)
