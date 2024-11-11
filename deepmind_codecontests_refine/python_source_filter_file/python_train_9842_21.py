import math
tab=[float(i) for i in input().split()]
d=tab[0]
h=tab[1]
v=tab[2]
e=tab[3]
he=4*v/(math.pi*d**2)
if v<=he :
	print("NO")
else :
	t=h/(he-v)
	print("YES")
	print(t)