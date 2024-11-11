s,a,b,a1,b1=map(int,input().split())
a=s*a+2*a1
b=s*b+2*b1

if a>b:
	print('First')
elif b>a:
	print("Second")
else:
	print("Friendship")

