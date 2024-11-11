a,b,c=map(int,input().split())
p=c-a-b
if p**2>4*a*b:
	print("Yes")
else:
	print("No")