a,b,c,d=map(int,input().split())
misha=max(3*a//10,249*a//250*c)
vasya=max(3*b//10,249*b//250*d)
if vasya==misha:
	print("Tie")
elif vasya>misha:
	print("Vasya")
else:
	print("Misha")
