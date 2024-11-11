a,b,c=[int(i)for i in input().split()]
d=0

for i in range(a,b):
	if c%i==0:
		d=d+1
print(d)