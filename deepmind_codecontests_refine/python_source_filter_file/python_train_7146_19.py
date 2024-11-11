# your code goes here
from math import sqrt
def sq(x):
	return x**2
def dist(a, b, p, q):
	return sqrt(sq(a-p)+sq(b-q))
def solvequad(a, b, c):
	d = sqrt(sq(b)-4*a*c)
	return ((-b+d)/(2*a), (-b-d)/(2*a))

r, x1, y1, fx, fy = map(int, input().split())
#print(sqrt(sq(x1-fx)+sq(y1-fy)))
if sqrt(sq(x1-fx)+sq(y1-fy)) > r+5e-7:
	print(x1, y1, r)
else:
	if(fx == x1):
		rc = max(abs(fy-(y1+r)), abs(fy-(y1-r)))/2
		if fy > y1:
			yc = (fy - rc)	
		else:
			yc = ( fy + rc )
		 
		print(x1,yc, rc)
		'''if(fy==y1):
		
			rc = max(abs(fx-(x1+r)), abs(fx-(x1-r)))/2
			if fx > x1:
				xc = fx - rc 
			else:
				xc = fx + rc 
			
			print( xc,y1, rc)'''
	else:
		l = dist(x1, y1, fx, fy)
		x = x1 + (x1-fx)/l*r
		y = y1 + (y1-fy)/l*r
	
		xc = (x + fx)/2
		yc = (y + fx)/2
		rc = dist(x, y, fx, fy)/2
		print(xc, yc, rc)