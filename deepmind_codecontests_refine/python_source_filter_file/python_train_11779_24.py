x,y,z=map(int,input().split())
g,p,b=map(int,input().split())
f=0
if x < g:
	g=g-x
	if y <= g + p:
		while(y != 0):
			if g > 0:
				g-=1
			else:
				p-=1
			y-=1
		if z <= g + p + b:
			f=1
			print("YES")
if f == 0:
	print("NO")