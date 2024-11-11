l = [int(x) for x in input().split()]
l.sort()
s = sum(l)
a = int(s/3)
s-=l[2]
if(s<a):
	print(s/3)
else:
	print(a)