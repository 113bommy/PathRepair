def main():
	n = int(input())
	print(solver(n))

def solver(n):
	factors = [2, 3, 5, 7]
	singles = n // 2 + n // 3 + n // 5 + n // 7
	pairs = n // (2 * 3) + n // (2 * 5) + n // (2 * 7) + \
	n // (3 * 5) + n // (3 * 7) + n // (5 * 7)
	triples = n // (2 * 3 * 5) + n // (2 * 3 * 7) + \
	n // (2 * 5 * 7) + n // (3 * 5 * 7)
	quads = n // (2 * 3 * 5 * 7)
	return n - singles + pairs - triples + quads