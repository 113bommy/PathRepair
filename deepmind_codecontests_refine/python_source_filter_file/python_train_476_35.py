a,b,c,d,e=map(int,input().split())
x=2*d+a*b
y=2*e+a*c
if x>y:
	print("First")
elif x<y:
	print("Second")
else:
	print("Friendship")
