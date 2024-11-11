line = input().split()
n, m = int(line[0]), int(line[1])
targets = [int(i) for i in input().split()]
current = 1
moves = 0
for i in targets:
    moves += i - current if i >= current else i + m - current
    current = i
print(moves)