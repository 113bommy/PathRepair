def main(): 
	n = int(input())
	a = int(input())
	b = int(input())
	c = int(input())
	print(solver(n, a, b, c))

def solver(n, a, b, c):
	if a < b - c:
		return n // a
	else:
		if a > b:
			if n < b:
				return 0
			return (n - b) // (b - c) + 1
		else:
			if n < b:
				return n // a
			bs = (n - b) // (b - c) + 1
			rem = n - bs * (b - c)
			return bs + rem // a

main()
#print(solver(10, 11, 9, 8))