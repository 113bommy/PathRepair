a,b = map(int,input().split())
if a>=b :
	print(b,int((a-b)/2))

elif b>a:
	print(a,int(a-b)/2)