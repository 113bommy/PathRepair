import os, sys, math
import collections

if os.path.exists('testing'):
	name = os.path.basename(__file__)
	if name.endswith('.py'):
		name = name[:-3]
	src = open(name + '.txt', encoding='utf8')
	input = src.readline

def solve():
	global xs
	xs = list(sorted(xs))
	min_region_index = xs[0] - 1
	max_region_index = xs[-1] + 1
	border_index = 2 * 10 ** 9
	
	prev = None
	regions = []
	for x in xs:
		if prev is not None and x - prev > 1:
			regions.append((prev + 1, x - 1))
		prev = x
	
	ys = []
	min_dist = 0
	current_dist = 1
	while len(ys) < m:
		region_index = 0
		if len(ys) < m and -border_index <= min_region_index:
			ys.append(min_region_index)
			min_dist += current_dist
			min_region_index -= 1
		if len(ys) < m and max_region_index <= border_index:
			ys.append(max_region_index)
			min_dist += current_dist
			max_region_index += 1
		while len(ys) < m and region_index < len(regions):
			a, b = regions[region_index]
			if a < b and len(ys) + 2 <= m:
				ys.append(a)
				ys.append(b)
				a += 1
				b -= 1
				min_dist += current_dist * 2
				if a <= b:
					regions[region_index] = (a + 1, b - 1)
				else:
					regions[region_index] = regions[-1]
					regions.pop()
					continue
			else:
				ys.append(a)
				min_dist += current_dist
				regions[region_index] = regions[-1]
				regions.pop()
				continue
			region_index += 1
		current_dist += 1
	return min_dist, ys

def integers():
	return map(int, input().strip().split()) 

def array_of_integers(q):
	return [
		tuple(map(int, input().strip().split())) for _ in range(q)
	]

n, m = integers()
xs = list(integers())
res, ys = solve()
print(res)
print(' '.join(map(str, ys)))


# . . . . . . . . . . . . . . 
# * *   *       * * *
#   *   *   *       * * *