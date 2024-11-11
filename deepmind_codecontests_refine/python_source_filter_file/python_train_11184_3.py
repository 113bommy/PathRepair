from math import *
a,b=map(int,input().split())
def gen(n):
	for x in range(1,n):
		y = round(sqrt(n*n-x*x))
		if x*x+y*y == n*n:
			yield (x,y)
for u in gen(a):
	for v in gen(b):
		if u[0]*v[0]-u[1]*v[1]==0 and u[0]!=u[1]:
			print("YES\n0 0")
			print(u[0],u[1])
			print(v[0],-v[1])
			exit()
print("NO")
