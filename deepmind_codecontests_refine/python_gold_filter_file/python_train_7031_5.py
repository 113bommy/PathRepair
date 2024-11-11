import sys
I=sys.stdin.readline


p1,p2,p3,p4,a,b=map(int,I().split())


x=min(p1,p2,p3,p4)

if x<=a:
	print(0)
else:
	if x>b:
		print(b-a+1)
	else:
		print(x-a)