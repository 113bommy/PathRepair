from math import *
MOD=10**9+7
n,k=list(map(int, input().split()))
a=list(map(int, input().split()))
b=list(map(int, input().split()))
temp= pow(10,k-1)
ans=1
for i in range(len(a)):
	totDiv = ceil((temp*10 - 1)/a[i])
	num1= temp*(b[i])
	num2= temp*(b[i]+1)
	smaller= ceil(num1/a[i])
	larger=ceil(num2/a[i])
	totDiv+=(smaller-larger)
	ans= (ans*totDiv)%MOD
print(int(ans))
