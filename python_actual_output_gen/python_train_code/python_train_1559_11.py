a,b = map(int,input().split())
x = list(input())
z = set(x)
v =[]
if len(z) == b:
	for i in x:
		v.append(x.count(i))
	print(min(v)*3)
else:
	print(0)

