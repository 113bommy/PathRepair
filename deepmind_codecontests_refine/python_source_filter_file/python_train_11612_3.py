def main():
	(h1, h2) = (int(x) for x in input().split())
	(a, b) = (int(x) for x in input().split())
	print(solver(h1, h2, a, b))

def solver(h1, h2, a, b):
	if a <= b:
		# must reach before 1st day
		if a * 7 >= h2 - h1:
			return 0
		else:
			return -1
	else:
		# 1st day
		h = h1 + a * 8
		if h >= h2:
			return 0
		else:
			dayClimb = 12 * (a - b)
			return (h2 - h - 1) // dayClimb + 1

main()
