r,x1,y1,x2,y2=map(int,input().split())

def dist(x1,x2,y1,y2):
	return(((x1-x2)**2+(y1-y2)**2)**0.5)
rr=dist(x1,x2,y1,y2)
if rr>=r:
	print(x1,y1,r)
elif rr==0:
	rrr=r/2
	it=(x2+rrr)
	itt=y2
	print(it,itt,rrr)
else:

	rrr=(rr+r)/2
	it=(x2+(x1-x2)*rrr/rr)
	itt=(y2+(y1-y2)*rrr/rr)
	print(it,itt,rrr)