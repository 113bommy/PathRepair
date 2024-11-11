from math import gcd
n,m=map(int,input().split())
n-=m
a=list(map(int,input().split()))
b=list(map(int,input().split()))
if n<0:
	print("0/1")
elif n==0:
	g=gcd(a[0],b[0])
	if b[0]==0:
		print("Infinity")
	else:
		if b[0]>0:
			print(str(a[0]//g)+'/'+str(b[0]//g))
		else:
			print(str(-a[0]//g)+'/'+str(-b[0]//g))
else:
	if a[0]*b[0]>0:
		print("Infinity")
	else:
		print("-Infinity")
