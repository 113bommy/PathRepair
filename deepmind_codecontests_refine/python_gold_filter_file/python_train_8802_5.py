# Check Examples

#python 3.7.1

a = [int(x) for x in input().strip().split(' ')]
a.sort()
t=a[2]-a[1]
if t>0:
	t-=1
d=a[2]-a[0]
if d>0:
	d-=1
print(d+t)