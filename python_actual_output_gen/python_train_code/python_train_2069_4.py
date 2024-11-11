x1,y1=map(int,input().split())
x2,y2=map(int,input().split())
x,y=x2,y2
if abs(x1-x2)>1:
	if x1>x2:
		x=x2+1
	else:
		x=x2-1
if abs(y1-y2)>1:
	if y1>y2:
		y=y2+1
	else:
		y=y2-1
if x==x2 or y==y2:
	print(8)
else:
	print(8+2*(abs(x1-x)+abs(y1-y)))
