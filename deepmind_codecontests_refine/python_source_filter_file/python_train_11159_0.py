from math import *
 
n = int(input())
 
a = []
o = []
even = 0
odd = 0
for i in range(n):
	t = int(input())
	if t % 2 == 0:
		a.append(t // 2)
	else:
		if odd == 0:
			odd = 1
			a.append((t + 1) // 2)
		else:
			odd = 0
			a.append(t / 2)
 
 
for e in a:
	print(e)