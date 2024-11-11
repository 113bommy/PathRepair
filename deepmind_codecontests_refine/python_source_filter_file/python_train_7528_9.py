def check(a, i):
	c = 0
	if abs(a[i]-a[i+2]) + 2 != abs(a[i] - a[i+1]) + 1 + abs(a[i+1] - a[i+2]) + 1:
		if abs(a[i]-a[i+3]) +3 != abs(a[i]-a[i+1]) + 1  + abs(a[i+1] - a[i+3]) + 2:
			if abs(a[i]-a[i+3]) + 3 != abs(a[i] - a[i+2]) + 2 + abs(a[i+2]-a[i+3]) + 1:
				if abs(a[i+1] - a[i+3]) +2 != abs(a[i+1]-a[i+2]) + 1 + abs(a[i+2]-a[i+3]) + 1:
					c = c + 1
	return c

def check1(a, i):
	c = 0
	if abs(a[i]-a[i+2]) + 2 != abs(a[i]-a[i+1]) + 1 + abs(a[i+1]-a[i+2])+1:
		c = c + 1

	return c

t = int(input())
for _ in range(t):

	n = int(input())
	a = [int(d) for d in input().split()]

	if len(a) == 1:
		print(1)
	elif len(a) == 2:
		print(3)
	elif len(a) == 3:
		if abs(a[0]-a[2]) + 2 != abs(a[1]-a[2]) + 1 + abs(a[0] - a[1]) + 1:
			print(5)
		else:
			print(6)

	else:
		c = n + n-1
		for i in range(n-3):

			c = c + check(a, i)

		for i in range(n-2):
			c = c+ check1(a,i)

		print(c)