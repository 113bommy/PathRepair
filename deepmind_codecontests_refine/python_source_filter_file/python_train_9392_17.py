for _ in range(int(input())):
	a,b,c,r=map(int,input().split())
	a,b=min(a,b),max(a,b)
	x,y=c-r,c+r
	if a<x<b and a<y<b:
		print(b-a-2*r)
	elif a<x<b:
		print(x-a)
	elif a<y<b:
		print(b-y)
	else:
		if x<a<b<y:
			print(0)
		else:
			print(b-a)