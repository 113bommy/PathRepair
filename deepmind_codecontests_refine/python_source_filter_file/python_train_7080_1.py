import math

def pr8(a):
	print("{:.10}".format(a[0]),end=" ")
	print("{:.10}".format(a[1]))

def koch(n,p1,p2):
	if n==0:
		return
	s=[0 for i in range(2)]
	t=[0 for i in range(2)]
	u=[0 for i in range(2)]
	
	s[0]=(2*p1[0]+1*p2[0])/3
	s[1]=(2*p1[1]+1*p2[1])/3
	t[0]=(1*p1[0]+2*p2[0])/3
	t[1]=(1*p1[1]+2*p2[1])/3
	
	rad=math.radians(60)
	
	u[0]=(t[0]-s[0])*math.cos(rad)-(t[1]-s[1])*math.sin(rad)+s[0]
	u[1]=(t[0]-s[0])*math.sin(rad)+(t[1]-s[1])*math.cos(rad)+s[1]
	
	koch(n-1,p1,s)
	#pr8(s)
	print(*s)	
	koch(n-1,s,u)
	#pr8(t)
	print(*t)
	koch(n-1,u,t)
	#pr8(u)
	print(*u)
	koch(n-1,t,p2)
	
n=int(input())
p1=[0,0]
p2=[100,0]

print(*p1)
koch(n,p1,p2)
print(*p2)

