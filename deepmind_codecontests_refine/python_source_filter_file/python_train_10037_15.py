import sys

input = sys.stdin.readline

def solve():
	r = []
	for c in input().strip():
		r.append(c)
		while True:
			if len(r) > 2 and r[-1] == r[-2] and r[-1] == r[-3]:
				r.pop()
			elif len(r) > 4 and r[-1] == r[-2] and r[-3] == r[-4]:
				r.pop()
			else:
				break
	print(''.join(r))


solve()
