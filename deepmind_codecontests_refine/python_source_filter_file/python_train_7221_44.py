moves = 0
n = []
for i in range(5):
	n.append(list(map(int, input().split())))

for i in range(1, 5):
	if 1 in n[i - 1]:
		moves += abs(3 - i)
		horizontal = n[i - 1].index(1) + 1
		moves += abs(3 - horizontal)
		
print(moves)