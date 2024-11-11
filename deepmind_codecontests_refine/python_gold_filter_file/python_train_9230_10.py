from math import sqrt

n, vb, vs = map(int, input().split())
stops = tuple(map(int, input().split()))
a, b = map(int, input().split())

def time(x):
	return x / vb + distance((x, 0), (a, b)) / vs

def distance(p1, p2):
	return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2))

#goal = a - b * vs / sqrt(pow(vb, 2) - pow(vs, 2))

best, m, n = time(stops[n - 1]), n - 1, n - 2

while n > 0:
	#print("Current best is " + str(best) + " with  index " + str(m))
	tmp = time(stops[n])
	if tmp < best:
		best, m = tmp, n
	n -= 1

print(m + 1)