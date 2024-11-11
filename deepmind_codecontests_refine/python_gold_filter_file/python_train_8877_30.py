# Author : shadoX #
import sys
input=sys.stdin.buffer.readline
ri=lambda: int(input())
rl=lambda: list(map(int,input().split()))
rs=lambda: input().decode().rstrip('\n\r')
wrt=sys.stdout.write
pr=lambda *args,end='\n': wrt(' '.join([str(x) for x in args])+end)
xrange=lambda args: reversed(range(args))
cdiv=lambda x,y: (-(-x//y))
enum=enumerate; inf=float('inf')
mod=10**9 + 7
# Am I debugging ? Check if I'm using same variable name in two places
# fun() returning empty list ? check new=temp[:] or new=temp

Cases=ri()
for Case in range(Cases):
	a,b,c,d=rl()
	print(max(a+b,c+d))