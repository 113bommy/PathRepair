a,b = map(int,input().split())
s=a+b
if s%2 != 0:
	print("IMPOSSIBLE")
else:
	print(s/2)
	
