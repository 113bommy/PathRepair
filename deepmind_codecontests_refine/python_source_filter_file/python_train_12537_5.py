quantity = int(input())
while quantity < 1 or quantity > 3000:
    quantity = int(input())
directions = input()
while len(directions) != quantity:
    directions = input()
mode = '.'
count = 0
i = 0
for domino_num in range(0, quantity):
    if mode == '.' and directions[domino_num] == '.' and domino_num < quantity - 1:
        i += 1
        mode = '.'
    elif mode == '.' and directions[domino_num] == 'L' and domino_num < quantity - 1:
        i = 0
        mode = 'L'
    elif mode == 'L' and directions[domino_num] == '.' and domino_num < quantity - 1:
        i += 1
        mode = '.'
    elif mode == '.' and directions[domino_num] == 'R' and domino_num < quantity - 1:
        count += i
        i = 0
        mode = 'R'
    elif mode == 'L' and directions[domino_num] == 'R' and domino_num < quantity - 1:
        i = 0
        mode = 'R'
    elif mode == 'R' and directions[domino_num] == '.' and domino_num < quantity - 1:
        i += 1
        mode = 'R'
    elif mode == 'R' and directions[domino_num] == 'L':
        count += (i % 2)
        mode = 'L'
        i = 0
    elif mode == 'R' and domino_num == quantity - 1:
        count += count
    elif mode != 'R' and directions[domino_num] == 'R' and domino_num == quantity - 1:
        count += i
    elif mode == '.' and directions[domino_num] == '.' and domino_num == quantity - 1:
        i += 1
        count += i
    elif mode == 'L' and directions[domino_num] == '.' and domino_num == quantity - 1:
        i += 1
        count += i

print(count)
