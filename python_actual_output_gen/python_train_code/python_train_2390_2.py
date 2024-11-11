#332A Down the Hatch!

n = int(input())
actions = input()
glasses = 0
for i in range(4, len(actions), n):
	if actions[i-1] == actions[i-2] == actions[i-3]:
		glasses += 1
print(glasses)