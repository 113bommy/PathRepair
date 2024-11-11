from math import sqrt

n = int(input())
a = 1
b = 1
count = 0 
for a in range(1, n+1):
	# print('')
	for b in range(a, n+1):
		# print(a, b)
		c = sqrt(a**2 + b**2)
		cint = int(c)
		if c==cint and c<=n:
			count += 1
print(count)