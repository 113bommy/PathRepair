

def solution(n, x, y):
	_max = y - (n - 1)
	maxs = [_max] + [1] * (n - 1)

	if _max > 0 and sum(map(lambda x: x ** 2, maxs)) >= x:
		return maxs

	return -1


if __name__ == "__main__":
	n, x, y = map(int, input().rstrip().split(" "))

	sol = solution(n, x, y)	

	if sol == -1:
		print(-1)
	else:
		for s in sol:
			print(s)
