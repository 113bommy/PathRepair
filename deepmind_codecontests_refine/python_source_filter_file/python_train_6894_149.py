from math import gcd
for n in range(int(input())):
	a,b=map(int,input().split())
	if b%a!=0:
		print('NO')
	else:
		print('YES')