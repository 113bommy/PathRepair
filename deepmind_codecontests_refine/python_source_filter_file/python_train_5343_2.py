import sys

input = sys.stdin.readline
a = [(0, 0),(2, 0),(0, 0),(2, 1)]
h = [(1, 0),(1, 0),(3, 0),(0, 0)]
z = [(0, 0),(0, 0),(0, 0),(0, 0)]

def solve():
	n = int(input())
	vars = dict()
	last = None
	for i in range(n):
		tmp = input().split()
		if tmp[1] == ':=':
			v1 = None
			if tmp[2][0] == 'a':
				v1 = a
			elif tmp[2][0] == 'h':
				v1 = h
			else:
				v1 = z
			for j in tmp[2][1:]:
				if j == 'a':
					v2 = a
				elif j == 'h':
					v2 = h
				else:
					v2 = z
				v = [(v2[v1[i][0]][0],v2[v1[i][0]][1]+v1[i][1]) for i in range(4)]
				v1 = v
			vars[tmp[0]] = v1
			last = v1
		else:
			v1 = vars[tmp[2]]
			v2 = vars[tmp[4]]
			last = [(v2[v1[i][0]][0],v2[v1[i][0]][1]+v1[i][1]) for i in range(4)]
			vars[tmp[0]] = last
	print(last[0][1])

for i in range(int(input())):
	solve()
