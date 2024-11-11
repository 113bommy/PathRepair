from itertools import permutations as P

n, m = map(int, input().split())
a = n-1
b = m-1
x = 0
y = 0
c = 0
while a:
	x += 1
	a = a//7
if x == 0:
	x = 1
while b:
	y += 1
	b = b//7
if b == 0:
	b = 1
if x+y > 7 or x+y == 0:
 	print(0)
else:
	r = x+y
	l = list(P('0123456', r))
	for ele in l:
		a = 0
		b = 0
		for i in range(x):
			a += int(ele[i])*(7**(x-i-1))
		for i in range(x, r):
			b += int(ele[i])*(7**(r-i-1))
		if a < n and b < m:
			c += 1
			#print(a, b, end = ' ')
			#print()
	print(c)
