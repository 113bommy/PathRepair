
x1,y1=map(int,input().split())
x2,y2=map(int,input().split())
if (x2-x1)>=0 and (y2-y1)>=0:
	if (x2-x1)<(y2-y1):
		print(y2-y1)
	else:
		print(x2-x1)
else:
	if (x2-x1)>(y2-y1):
		print(abs(y2-y1))
	else:
		print(abs(x2-x1))