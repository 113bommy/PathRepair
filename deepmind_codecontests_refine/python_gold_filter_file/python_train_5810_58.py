a,b=map(int,input().split())
if a%2 != b%2:
	print("IMPOSSIBLE")
else:
	k=(a+b)//2
	print(k)