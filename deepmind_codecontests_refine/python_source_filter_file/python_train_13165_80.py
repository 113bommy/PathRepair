import itertools
import math

answers = [2, 5, 2, 3, 3, 4, 2, 4, 1, 2]

def main():
	a, b = list(map(int, input()))
	print(answers[a] * answers[b])

if __name__ == "__main__":
	main()
