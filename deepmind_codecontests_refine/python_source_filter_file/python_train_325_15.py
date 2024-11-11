n, x, y = [int(n) for n in input().split(' ')]
num = input()

i = 0
moves = 0
while i < x:
    c = num[-i + 1]
    correct = c == ('1' if i == y else '0')
    if not correct:
        moves += 1
    i += 1

print(moves)
