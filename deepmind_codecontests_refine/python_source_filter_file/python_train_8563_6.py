import math
n = int(input())
ans = 0
for i in range(2,n):
	a = n
	while a:
		ans+=(a%i)
		a//=i
a+=2
d = math.gcd(n,a)
print(str(ans//d)+"/"+str((n-2)//d))