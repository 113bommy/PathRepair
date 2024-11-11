a,b=map(int,input().split())
if a>b:
	print(b,(a-b)//2)
if a<b:
	print(a,(b-a)//2)
if a==b:
	print(a,0)