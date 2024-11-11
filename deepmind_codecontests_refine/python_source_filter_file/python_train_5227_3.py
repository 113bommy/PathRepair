import os, sys, math

def solve(seq, k):
	seq = [ 1 if a == '(' else -1 for a in seq ]
	size = len(seq)
	result = []

	def rotate(fr, to):
		assert fr <= to
		result.append((fr, to))
		while fr < to:
			seq[fr], seq[to] = seq[to], seq[fr]
			fr += 1
			to -= 1
		# print(''.join('(' if q > 0 else ')' for q in seq))
	def split(p1, p2):
		if p1 + 1 == p2:
			return False
		assert seq[p1] > 0 and seq[p2] < 0, (seq, p1, p2)
		i = p1
		while seq[i] > 0:
			i += 1
		rotate(p1 + 1, i)
		return True
	def merge(p):
		assert seq[p] < 0 and seq[p + 1] > 0, (p, seq)
		rotate(p, p + 1)
	d = 0
	x = 0
	while x < size:
		d += seq[x]
		x += 1
		if d < 0:
			start = x - 1
			while d < 0:
				d += seq[x]
				x += 1
			assert d == 0
			rotate(start, x - 1)

	zero_points = [ -1 ]
	d = 0
	for x in range(size):
		d += seq[x]
		if d == 0:
			zero_points.append(x)
	start = len(zero_points) - 1
	if start < k:
		zero_points_index = 0
		while start < k:
			p1 = zero_points[zero_points_index] + 1
			p2 = zero_points[zero_points_index + 1]
			if not split(p1, p2):
				zero_points_index += 1
			else:
				zero_points[zero_points_index] = p1 - 1 + 2
				start += 1
	elif start > k:
		zero_points_index = 1
		while start > k:
			merge(zero_points[zero_points_index])
			start -= 1
			zero_points_index += 1
	return result

#res = solve('(R' + ('(R)R' * 2) + ')')

if os.path.exists('testing'):
	name = os.path.basename(__file__)
	if name.endswith('.py'):
		name = name[:-3]
	src = open(name + '.in.txt', encoding='utf8')
	input = src.readline
num = int(input().strip())
for x in range(num):
	n, k = map(int, input().strip().split())
	n = input().strip()[:n]
	res = solve(n, k)
	print(len(res))
	for q in res:
		print(' '.join(map(str, q)))
