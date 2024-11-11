y,b,r=map(int,input().split())
if y<b and y<r:
	if y<r-1:
			print(3*y+3)
	else:
		    print(3*r-3)
elif b<=y and b<r:
	print(3*b)
else:
	print(3*r-3)