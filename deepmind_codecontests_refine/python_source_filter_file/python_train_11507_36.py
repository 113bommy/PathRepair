import math
def choose(n, a):
	c = math.factorial(n)
	d = math.factorial(a)*math.factorial(n-a)
	return c/d
n = int(input())
x = 0
a = 5
for i in range(3):
	x += choose(n, a)
	a += 1
print(int(x))