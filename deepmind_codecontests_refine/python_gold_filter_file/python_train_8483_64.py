r,h=map(int,input().split())
if r>=h:
	r=r-h
	r//=2
	print(h,r)
else:
	h=h-r
	h//=2
	print(r,h)