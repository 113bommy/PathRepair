# import sys
# sys.stdin  = open("input.txt","r")
# sys.stdout = open("output.txt","w")
import math

R,x1,y1,x2,y2 = map(float, input().strip().split(' '))
d = math.sqrt((x1-x2)**2 + (y1-y2)**2)
if(x1==x2 and y1==y2):
	print(x1/2,y1,R/2,sep=" ")
elif(d>=R):
	print(x1,y1,R,sep=" ")
elif(d<R):
	x = ((d+R)*x1 - R*x2)/d
	y = ((d+R)*y1 - R*y2)/d
	x = (x + x2)/2
	y = (y + y2)/2
	r = (d+R)/2
	print(x,y,r,sep=" ")