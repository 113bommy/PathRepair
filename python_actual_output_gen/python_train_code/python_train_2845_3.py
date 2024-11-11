# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out1.out",'w')
n=int(input())-1
a=[int(input()) for i in range(3)]
x=0
if n and a[0]<=a[1]:
	if a[2]<=a[0]:
		x=(a[0]+a[2]*(n-1))
	else:
		x=a[0]*n		
elif n and a[1]>a[0]:
	if a[2]<=a[1]:
		x=(a[1]+a[2]*(n-1))
	else:
		x=a[1]*n		
print(x)		