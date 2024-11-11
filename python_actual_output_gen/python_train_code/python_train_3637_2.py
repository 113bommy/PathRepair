a , b = map(int , input().split())
min = 100
for i in range(0,a):
	x , y = map(int , input().split())
	z = x/y
	if min > z:
		min = z
print(z*b)		