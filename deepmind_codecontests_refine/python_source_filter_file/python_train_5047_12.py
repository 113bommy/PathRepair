a,b = [int(x) for x in input().split()]
a,b = max(a,b), min(a,b)
hsl = 0
while (a%b!=0):
	hsl = hsl + a/b
	a = a%b
	a,b = max(a,b), min(a,b)
hsl = hsl + a/b
print (int(hsl))
	