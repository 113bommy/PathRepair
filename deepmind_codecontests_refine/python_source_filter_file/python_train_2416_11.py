for _ in range(int(input())):
	n = int(input())
	pins = [list(map(int, input())) for _ in range(n)]
	changes = 0
	for i in range(n):
		change = 0
		if pins[i] in pins[:i] + pins[i + 1:]:
			change = 1
			pins[i][0] = (pins[i][0] + 1) % 10
		changes += change
	print(changes)
	for pin in pins:
		print(*pin, sep = "")