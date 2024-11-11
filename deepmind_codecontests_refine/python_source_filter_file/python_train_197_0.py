from math import factorial
def comb (x,y):
	return factorial(x)//factorial(x-y)//factorial(y)

w,h,ax,ay,bx,by=map(int,input().split())
dx=abs(ax-bx)
dx=min(dx,w-dx)
dy=abs(ay-by)
dy=min(dy,h-dy)
an=1
if dx*2==w:an*=2
if dy*2==h:an*=2
an*=comb(dx+dy,dx)
print(an%int(1E9+7))