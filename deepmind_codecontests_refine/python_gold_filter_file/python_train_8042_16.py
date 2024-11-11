'''input
2
1
5
'''
import math
def solve():
	n = int(input())
	l = [1,0,0,1] * n
	for i in range(n*4-n,n*4):
		l[i] = 0

	def eval(idx):
		return l[i]*8 + l[i+1]*4 + l[i+2]*2 + l[i+3]

	for i in range(0,n*4,4):
		d = eval(i)
		if d == 0:
			d = 8
		print(d,end="")
	print()

t = 1
t = int(input())
while t > 0:
	t-=1
	solve()