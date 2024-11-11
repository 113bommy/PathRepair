s, ls, cs = int(input()), [], 0
for _ in range(s):
	ls.append([x == "X" for x in input()])
	if _ > 1:
		for i in range(2, s):
			if ls[_][i] and ls[_][i-2] and ls[_-1][i-1] and ls[_-2][i] and ls[_-2][i-2]: cs+=1
print(cs)