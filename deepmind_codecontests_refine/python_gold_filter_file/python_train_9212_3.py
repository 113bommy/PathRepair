ii=lambda:int(input())
kk=lambda:map(int, input().split())
ll=lambda:list(kk())
 
a,b,c,d,e,f=kk()
al = [a,b,c,d,e,f]
s = sum(al)
area = a*b+c*d+e*f
side = int(area**.5)
if side**2 != area or side not in al:
	print(-1)
	exit()
if al.count(side) == 3:
	# as bs cs
	if s == 4*side:
		rest = [a for a in al if a != side]
		print(side)
		for _ in range(side):
			print("".join(["A"*rest[0], "B"*rest[1], "C"*rest[2]]))
elif al.count(side) > 1:
	print(-1)
else:
	x=al.index(side)
	y=x^1
	res = al[y]
	a,b=min(x,y),max(x,y)
	s1 = "ABC"[a//2]
	s23 = [s for s in "ABC" if s != s1]
	rest = al[:a]+al[b+1:]
	res = side - res
	a,b=[rest[0],rest[1]],[rest[2],rest[3]]
	if not (res in a and res in b):
		print(-1)
		exit()
	o1,o2 = a[a.index(res)^1],b[b.index(res)^1]
	print(side)
	for _ in range(al[y]):
		print(s1*side)
	for _ in range(res):
		print("".join([s23[0]*o1,s23[1]*o2]))