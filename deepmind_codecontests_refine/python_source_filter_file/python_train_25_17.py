import math
import sys
import collections
import bisect

#sys.setrecursionlimit(1000000000)

input = sys.stdin.readline
flush = sys.stdout.flush

readint    =lambda: int(input())
readintm   =lambda: map(int,input().strip().split())
readintl   =lambda: list(map(int,input().strip().split()))

readfloatm =lambda: map(float,input().strip().split())
readfloatl =lambda: list(map(float,input().strip().split()))

readstr    =lambda: input().strip()
readstrl   =lambda: list(input().strip())

join       =lambda x,l: x.join(map(str,l))
print      =lambda *x: sys.stdout.write(" ".join(map(str,x))+'\n')
printl	   =lambda l: sys.stdout.write(" ".join(map(str,l))+'\n')

ceil       =lambda x,y: (x+y-1)//y
mod        =1000000007

# START HERE

for _ in range(readint()):
	n = readint()
	board = [readstrl() for i in range(n)]
	a, b =  board[1][0], board[0][1]
	x, y = board[-1][-2], board[-2][-1]
	c = 0
	out = []
	if a == b:
		if x == a:
			c += 1
			out.append(f"{n} {n-1}")
		if y == a:
			c += 1
			out.append(f"{n-1} {n}")
		print(c)
	else: # a != b
		if x == y:
			if a == x:
				out.append("2 1")
			else:
				out.append("1 2")
			print(1)
		else:
			if a == 1:
				out.append("2 1")
			elif b == 1:
				out.append("1 2")
			if x == 0:
				out.append(f"{n} {n-1}")
			elif y == 0:
				out.append(f"{n-1} {n}")
			print(2)
	for point in out:
		print(point)