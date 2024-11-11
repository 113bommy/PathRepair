X, Y, x0, y0 = [int(x) for x in input().split()]
commands = input()
pos = [x0, y0]

count = X * Y
result = [0] * len(commands)

visited = {}

for i in range(len(commands)):

	key = pos[0] + 4 * (pos[1] - 1)

	if key not in visited:
		result[i] = 1
		count -= 1
		visited[key] = 0

	if commands[i] == "U" and (pos[0] - 1) > 0:
		pos[0] -= 1

	elif commands[i] == "D" and (pos[0] + 1) <= X:
		pos[0] += 1

	elif commands[i] == "L" and (pos[1] - 1) > 0:
		pos[1] -= 1

	elif commands[i] == "R" and (pos[1] + 1) <= Y:
		pos[1] += 1

print((' '.join([str(x) for x in result]) + " "), count)
