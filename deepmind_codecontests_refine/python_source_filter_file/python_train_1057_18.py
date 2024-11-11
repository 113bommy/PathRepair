





def sum_digits(n):
	r = 0
	while n:
		r, n = r + n % 10, n // 10
	return r


x,y,z=input().split(" ")

x=int(x)
y=int(y)
z=int(z)

if x%z==0 and y%z==0:
	print(x//z+y//z,0)
else:
	m=x%z
	n=y%z

	if m+n==z:
		print(x//z+y//z+1,min(m,n))

	elif m+n<z:
		print(x//z+y//z,0)
	else:
		print(x//z+y//z+1,z-min(m,n))




