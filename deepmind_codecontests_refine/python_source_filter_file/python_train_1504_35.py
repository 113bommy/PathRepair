n = int(input())
l = -1000000001
r = 1000000001
for i in range(n):
	s, x, otv = input().split()
	x = int(x)
	if s == '>':
			if otv == 'Y' and l<x:
				l=x+1
			elif x<r and otv == 'N':
				r=x
	if s == '<':
		if otv == 'Y' and x<r:
			r=x-1
		elif x>l and otv == 'N':
			l=x
	if s == '<=':
		if otv == 'Y' and x<r:
			r=x
		elif x>l and otv == 'N':
			l=x+1
	if s == '>=':
		if otv == 'Y' and x>l:
			l=x
		elif x<r and otv == 'N':
			r=x-1
	
if l + 1 <=r and r != -1000000000:
	print(l+1)
elif l == r and abs(l) != 1000000000:
	print(l)
elif (l ==-1000000000) and (r == 1000000000):
	print(r - 5)
elif r == -1000000000:
	print(l - 5)
else:
	print('Impossible')