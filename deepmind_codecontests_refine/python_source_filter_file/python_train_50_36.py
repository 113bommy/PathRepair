buttons, bulbs = list(map(int, input().split(' ')))
status = [0]*(bulbs+1)
status[0] = 1
for l in range(buttons):
    numbers = list(map(int, input().split(' ')))
    for number in numbers:
        status[number] = 1

if status.count(0) == 0:
    print('YES')
else:
    print('NO')
