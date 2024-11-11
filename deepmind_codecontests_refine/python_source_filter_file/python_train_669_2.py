from sys import stdin
from itertools import product

lines = list(filter(None, stdin.read().split('\n')))

def parseline(line):
	return list(map(int, line.split()))

lines = list(map(parseline, lines))
n = lines[0][0]
assert len(lines) >= 4 * n + 1

class Unit:
	def __init__(self, x, y, a, b):
		self.pos = x, y
		self.home = a, b

def to_unit(l):
	return Unit(l[0], l[1], l[2], l[3])

def squads():
	for i in range(n):
		yield list(map(to_unit, lines[4*i+1:4*i+5]))

def is_90_degree(a, b, c, d):
	return 0 == sum((bi - ai) * (di - ci) for ai,bi,ci,di in zip(a,b,c,d))

def dist_sqr(a, b):
	return (b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2

def is_square(points):
	a, b, c, d = points
	if a == b == c == d:
		return False
	if not is_90_degree(a, b, c, d):
		b, d = d, b
		if not is_90_degree(a, b, c, d):
			a, b = b, a
			if not is_90_degree(a, b, c, d):
				return False
	if not (c[0] + d[0] == b[0] + a[0] and c[1] + d[1] == b[1] + a[1]):
		return False
	if not (dist_sqr(a, b) == dist_sqr(c, d)):
		return False
	return True

def rotate(point, pole, angle):
	result = point
	for i in range(angle):
		result = -result[1]+pole[1]+pole[0], result[0]-pole[0]+pole[1] 
	return result

def rotate_squad(squad, rotation):
	return [rotate(unit.pos, unit.home, angle) for unit, angle in zip(squad, rotation)]

rotations = list(product([0, 1, 2, 3], repeat=4))

INF = 10000000

for squad in squads():
	min_rotations = INF
	for rotation in rotations:
		if is_square(rotate_squad(squad, rotation)):
			min_rotations = min(min_rotations, sum(rotation))
	if min_rotations == INF:
		min_rotations = -1
	print(min_rotations)
