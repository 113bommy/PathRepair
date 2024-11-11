import math
R,x1,y1,x2,y2 = map(int,input().split())
r=R
dist = math.sqrt((x2-x1)**2+(y2-y1)**2)
if dist >= R :
	print(x1,y1,R)
elif x1==x2 and y1==y2:
	print(x1+R/2,y1,R/2)
else :
	x = (x1*(dist+r)-x2*r)/dist
	y = (y1*(dist+r)-y2*r)/dist
	dist = math.sqrt((x2-x)**2+(y2-y)**2)
	print((x+x2)/2,(y+y2)/2,dist/2)