import math
MOD=998244353
n = int(input())

for k in range(n):
	sum=0
	if (n-k>2):
		sum+=10*9*9*pow(10,n-2-k-1,MOD)*(n-k-3)
	sum%=MOD
	if (n-k>1):
		sum+=2*10*9*pow(10,n-2-k,MOD)
	else:
		sum=10
	print(sum,end=' ')
print()
