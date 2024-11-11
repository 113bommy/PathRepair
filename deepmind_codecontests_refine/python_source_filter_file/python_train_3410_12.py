n = int(input())
*a, = map(int, input().split())

s = set(a)

def solve(x, s):
	p = 1
	ret = [x]
	for d in range(32):
		if x + p in s:
			if x + 2 * p in s:
				return [x, x + p, x + 2 * p]
			if x - p in s:
				return [x - p, x, x + p]
			ret = [x, x + p]
		elif x - p in s:
			if x - 2 * p in s:
				return [x - 2 * p, x - p, x]
			ret = [x - p, x]
	return ret

best = []
for x in a:
	bestx = solve(x, s)
	if len(bestx) > len(best):
		best = bestx
print(len(best))		
print(' '.join(map(str, best)))


