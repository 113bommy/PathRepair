from math import ceil
from math import factorial
from collections import Counter
from operator import itemgetter
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
 
t = ii()
 
for i in range(t):
	a = input()
	l = a.count('L')
	r = a.count('R')
	u = a.count('U')
	d = a.count('D')

	x = min(l,r)
	y = min(u,d)

	if(x==0 and y==0):
		print(0)
	elif(x==0 and y>0) or (y==0 and x>0):
		print(1)
		if(x==0):
			print('UD')
		else:
			print('LR')
	else:
		s = 'L'*x + 'U'*y + 'R'*x + 'D'*y
		print(len(s))
		print(s)
