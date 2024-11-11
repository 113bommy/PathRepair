X,A,B=map(int,input().split())
if A>=B:
	print("deloicious")
elif A+B>X:
	print("dangerous")
else:
	print("safe")