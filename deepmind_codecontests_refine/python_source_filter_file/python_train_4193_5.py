

def main():
	from sys import stdin, stdout

	N = int(input())

	lines = [a.strip() for a in stdin.readlines()]

	count = 0
	k = 0
	while k < len(lines):
		row, col = lines[k].split(" ")
		row, col = int(row), int(col)
		k += 1

		grid = []
		for _ in range(row):
			grid.append(lines[k])
			k += 1

		for i in range(row - 2, -1, -1):
			if grid[i][-1] != "D":
				count += 1

		for j in range(col - 2, -1, -1):
			if grid[-1][j] != "R":
				count += 1

		print(count, "yo")
		count = 0

main()