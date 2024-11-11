a,b,c,d=[int(x) for x in input().split()]
if b/a>d/c:
	u=(b*c-a*d)
	v=(b*c)
else:
	u=(a*d-b*c)
	v=(a*d)

for i in range(2,min(u,v)+1):
	while  u%i==0 and v%i==0:
		u=u//i
		v=v//i
if u==0:
	print("0/1")
else:
	print(str(u)+"/"+str(v))
