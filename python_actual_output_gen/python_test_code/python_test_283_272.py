X,A,B=map(int,input().split())
if A>=B:
	print("delicious")
elif A<X and A+B>X :
	print("safe")
else:
	print("dangerous")