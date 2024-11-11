from sys import stdin, stdout
rl = lambda: stdin.readline()
rll = lambda: stdin.readline().split()

def pprint(M):
	for row in M:
		print(row)
	print("~~~")

def main():
	T = int(rl())
	for _ in range(T):
		board = []
		for _ in range(9):
			row = [int(x) for x in list(rll()[0])]
			board.append(row)
		sqs = [(0, 0), (1,3), (2,6), (3,1), (4,4), (6,8), (6,2), (7,5), (8,7)]
		for r, c in sqs:
			board[r][c] += 1
			if board[r][c] > 9:
				board[r][c] = 1 + (board[r][c] % 10)
		ans = ["".join(str(c) for c in r) for r in board]
		ans = "\n".join(row for row in ans)
		stdout.write(ans);stdout.write("\n")
	stdout.close()

if __name__ == "__main__":
	main()