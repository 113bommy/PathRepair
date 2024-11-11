def zip_sorted(a,b):

	# sorted  by a
	a,b = zip(*sorted(zip(a,b)))
	# sorted by b
	sorted(zip(a, b), key=lambda x: x[1])

	return a,b

a   = [int(n1) for n1 in input().split()]
b   = [int(n1) for n1 in input().split()]
c   = [int(n1) for n1 in input().split()]

count = 0
for i in range(1,(10**5)+1):
	a[0] = i
	b[1] = sum(a)-sum(b)
	if b[1]>0:
		if sum(a)==sum(b):
			c[2] = sum(a)-(b[1]+a[0])
			if c[2]>0:
				if sum(c)==sum(a)==sum(b)==(c[0]+b[0]+a[0])==(c[1]+b[1]+a[1])==(c[1]+b[1]+a[1]):
					count = 1
					break
				else:
					a[0] = 0
					b[1] = 0
					c[2] = 0
			else:
				a[0] = 0
				b[1] = 0
				c[2] = 0
		else:
			a[0] = 0
			b[1] = 0
			c[2] = 0
	else:
		a[0] = 0
		b[1] = 0
		c[2] = 0

print(*a)
print(*b)
print(*c)



'''
for i in range(n):
for j in range(n):
for k1 in range(len(a)):
for k2 in range(len(a)):
for k3 in range(len(a)):

'''