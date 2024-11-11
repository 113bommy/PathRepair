from itertools import repeat
from math import floor,ceil
def fill(s,a1,a2,a3,a4,c4,c7):
	if a1<c4 or a2<c7:
			return None
	f = s.index('4')
	sv = s.rindex('7')
	s = ''.join([s[:f],'4'*(a1-c4),s[f:sv],'7'*(a2-c7),s[sv:]])
	return s
a1,a2,a3,a4 = [int(x) for x in input().split()]
if abs(a3-a4)>1:
	print(-1)
else:
	s = ''
	if a3>a1 or a3>a2 or a4>a1 or a4>a2:
		print(-1)
		exit(0)
	c4 = 0
	c7 = 0
	if a3>a4:
		s = ''.join(repeat('47',a3))
		c4 = int(len(s)/2)
		c7 = len(s)-c4
		s = fill(s, a1, a2, a3, a4, c4, c7)
		if s:
			print(s)
		else:
			print(-1)
	elif a3<a4:
		s = ''.join(repeat('74',a4))
		c7 = int(len(s)/2)
		c4 = len(s)-c4
		s = fill(s, a1, a2, a3, a4, c4, c7)
		if s:
			print(s)
		else:
			print(-1)
	elif a3==a4:
		s = ''.join(repeat('47',a3))+'4'
		c4 = ceil(len(s)/2)
		c7 = len(s)-c4
		s = fill(s, a1, a2, a3, a4, c4, c7)
		if s:
			print(s)
		else:
			s = ''.join(repeat('74',a3))+'7'
			c7 = ceil(len(s)/2)
			c4 = len(s)-c7
			s = fill(s, a1, a2, a3, a4, c4, c7)
			if s:
				print(s)
			else:
				print(-1)