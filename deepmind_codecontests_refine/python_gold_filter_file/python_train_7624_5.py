import sys
input = sys.stdin.readline

t=int(input())
for _ in range(t):
	a,b=map(int,input().split())
	if a == b:
		x=2*a
		print(x**2)
	else:
		y=(min(a,b)*2)
		z=max(a,b)
		x=max(z,y)
		print(x**2)