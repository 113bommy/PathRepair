from math import ceil
m=0
for _ in range(int(input())):
	a,b=list(map(int,input().split()))
	while a!=0 and b!=0:
			if a>=b:
				m+=a//b
				a=a%b
			else:
				m+=b//a
				b=b%a
	print(m)