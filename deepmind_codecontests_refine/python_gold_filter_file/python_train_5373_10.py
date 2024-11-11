a=str(input())
n=int(input())
if len(a)<n:
	print("impossible")
else:
	a=set(a)
	print(max(0,n-len(a)))