#!/usr/bin/python3

import math

class StdIO:
	def read_int(self):
		return int(self.read_string())

	def read_ints(self, sep=None):
		return [int(i) for i in self.read_strings(sep)]

	def read_float(self):
		return float(self.read_string())

	def read_floats(self, sep=None):
		return [float(i) for i in self.read_strings(sep)]

	def read_string(self):
		return input()

	def read_strings(self, sep=None):
		return self.read_string().split(sep)

io = StdIO()


def closest(a, b, p):
	ax, ay = a
	bx, by = b
	px, py = p
	lx, ly = bx - ax, by - ay
	print(lx, ly)

	num = ax*lx - px*lx + ay*ly - py*ly
	den = lx*lx + ly*ly
	t = - num / den

	if t > 1.0:
		return b
	elif t < 0.0:
		return a
	else:
		return (ax + t*lx, ay + t*ly)


def dist(a, b):
	ax, ay = a
	bx, by = b
	return math.hypot(ax - bx, ay - by)


def main():
	n, px, py = io.read_ints()
	p = (px, py)

	prev = None
	first = None
	min_dst = float('inf')
	max_dst = 0
	for i in range(n):
		qx, qy = io.read_ints()
		q = (qx, qy)

		dst = dist(p, q)
		max_dst = max(max_dst, dst)

		if prev is None:
			prev = q
			first = q
			continue

		r = closest(prev, q, p)
		dst = dist(p, r)
		min_dst = min(min_dst, dst)

		prev = q

	r = closest(prev, first, p)
	dst = dist(p, r)

	min_dst = min(min_dst, dst)

	r = min_dst
	R = max_dst

	A = math.pi * (R*R - r*r)
	print(A)

if __name__ == '__main__':
	main()
