import math
ra,xa,ya,xb,yb = map(float, input().split())  
dis = math.sqrt(abs(xa-xb)*abs(xa-xb)+abs(ya-yb)*abs(ya-yb))
if(xa==xb and ya==yb):
	print(xa)
	print(ya+ra/2)
	print(ra/2)
else:
	if (dis<(ra*ra)):
		rb = (ra+dis)/2;
		blx = (xa-xb)/dis;
		xc = xa+((rb-(dis)))*blx;
		bly = (ya-yb)/(dis);
		yc = ya+((rb-(dis)))*bly;
		print(xc)
		print(yc)
		print(rb)
	else:
		print(xa)
		print(ya)
		print(ra)