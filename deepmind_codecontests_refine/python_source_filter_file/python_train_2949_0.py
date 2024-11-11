import math
a=[]
for s in[*open(0)][2::2]:
	D={};d=k=0
	for c in s:
		if c<'K':d+=1
		else:k+=1
		g=math.gcd(d,k);l=(d/g,k/g);D[l]=D.get(l,0)+1;a+=D[l],
print(*a)