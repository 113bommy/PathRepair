n=int(input())
l=[int(x) for x in input().split()]
l.sort()
x, y, z=l.count(l[0]), l.count(l[1]), l.count(l[2])
if(x>2):
	print((x*(x-1)*(x-2))//6)
elif x==1 and y>=2:
	print((y*(y-1))/2)
else:
	print(z)