def main():
	n = int(input())
	print(solver(n))

def solver(n):
	return pow(2, n + 1) - 2

main()

