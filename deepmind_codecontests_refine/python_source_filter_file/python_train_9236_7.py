from math import sqrt


def dist(x1, y1, x2, y2):
	return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)	


n, vb, vs = map(int, input().split())

x = list(map(int, input().split()))[1:]

xu, yu = map(int, input().split())

t = [(x[_] / vb + dist(x[_], 0, xu, yu), dist(x[_], 0, xu, yu), _) for _ in range(n - 1)]

print(min(t)[2] + 2)
