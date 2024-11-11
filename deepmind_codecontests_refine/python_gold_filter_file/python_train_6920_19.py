n,m=[int(x) for x in input().split()]
t=max(n,m)
v=min(n,m)
if t>=2*v:
	print(v)
else:
	print((n+m)//3)
