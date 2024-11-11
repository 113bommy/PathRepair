def solve(n: int, p: int, q: int, s: str):
	for a in range(n // p + 1):
		if (n - a * p) % q == 0:
			b = (n - a * p) // q

			print(a + b)

			for pos in range(0, a * p, p):
				print(s[pos : pos + p])

			for pos in range(a * p, n, q):
				print(s[pos : pos + q])

			return

	print(-1)


if __name__ == '__main__':
	n, p, q = map(int, input().split())

	s = input()

	solve(n, p, q, s)
