ties = a=int(input())
m=0
scarves = b=int(input())
vests = c=int(input())
jackets = d=int(input())
cost1 = e=int(input())
cost2 = f=int(input())
if f>=e:
	m+=((min(b,c,d))*f)
	m+=((d-min(b,c,d))*e)
elif e>f:
	m+=((min(a,d))*e)
	m+=min(b,c,(d-min(a,d)))*f
print(m)