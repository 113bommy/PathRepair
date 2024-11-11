import math
n = int(input())
ans = 0
for i in range(2,n):
	a = n
	while a:
		ans+=(a%i)
		a//=i
n-=2
d = math.gcd(ans,n)
print(str(ans//d)+"/"+str((n)//d))