a,b=input().split()
# print(a,b)
if int(a)<int(b):
	c=a
	d=b
else:
	c=b
	d=a
print(c)
z=0
for x in range(int(c),int(d)):
	z+=1
z=z//2
print(c,z)