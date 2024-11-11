def main():
	n = int(input())
	return solver(n)

def solver(n):
	if n % 3 == 0:
		return n // 3 * 2
	elif n % 3 == 1:
		return (2 * n + 1) // 3
	else:
		return (2 * (n - 1) + 1) // 3

main()
