def main():
	n, q = map(int, input().split())
	s = f".{input()}."
	pm = [input().split() for _ in range(q)]

	def is_outside(x:int) -> int:
		for point, move in pm:
			if s[x] == point:
				if move == "L":
					x -= 1
				else:
					x += 1
			if x == 0:
				return -1
			if x == n+1:
				return 1
		return 0

	ok, ng = 0, n+1
	while ng - ok > 1:
		mid = (ng + ok) >> 1
		if is_outside(mid) == -1:
			ok = mid
		else:
			ng = mid
	l = ok

	ng, ok = 0, n+1
	while ok - ng > 1:
		mid = (ng + ok) >> 1
		if is_outside(mid) == 1:
			ok = mid
		else:
			ng = mid
	r = ng

	print(max(r-l, 0))

if __name__ == '__main__':
    main()