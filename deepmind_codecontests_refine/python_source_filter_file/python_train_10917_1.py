def main():
	import sys

	for line in sys.stdin:
		a, b = map(int, line.split())
		c = a*b

		while a % b != 0:
			a, b = b, a%b

		print(b, c*b)

if __name__ == '__main__':
	main()