a,b,c=map(int,input().split())
if (a+b)<c:
	print(2*(a+b))
if (2*c)<a or (2*c)<b:print(2*((min(a,b))+c))   
else:print(a+b+c)