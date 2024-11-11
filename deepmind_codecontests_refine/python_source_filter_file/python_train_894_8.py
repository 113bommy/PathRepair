import math
n=int(input())
if n%2==0:
	a=n//2-1
	b=n//2+1
else:
	a=n//2
	b=n//2+1
flag=0
while flag==0:
	if math.gcd(a,b)==1:
		print(a,b)
		flag=1
	else:
		a=a-1
		b=b-1
