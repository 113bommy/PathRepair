import math
class Point:
	def __init__(self,x,y):
		self.x=x
		self.y=y
	def __str__(self):
		return str(self.x)+' '+str(self.y)
	
def koch(n,a,b):
	if n==0: return
	s=Point(0,0)
	t=Point(0,0)
	u=Point(0,0)
	th=math.pi*60/180
	s.x=(2*a.x+1*b.x)/3
	s.y=(2*a.y+1*b.y)/3
	t.x=(1*a.x+2*b.x)/3
	t.y=(1*a.y+2*b.y)/3
	u.x=(t.x-s.x)*math.cos(th)-(t.y-s.y)*math.sin(th)+s.x
	u.y=(t.x-s.x)*math.sin(th)+(t.y-s.y)*math.cos(th)+s.y
	
	koch(n-1,a,s)
	print(s)
	koch(n-1,s,u)
	print(u)
	koch(n-1,u,t)
	print(t)
	koch(n-1,t,b)

n=int(input())
a=Point(0,0)
b=Point(100,0)
print(a)
koch(n,a,b)
print(b)

