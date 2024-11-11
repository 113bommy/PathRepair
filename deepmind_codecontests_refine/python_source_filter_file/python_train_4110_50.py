a, b, c, d = map(int, input().split())
x = max(3 * a // 10, a - (a / 250))
y = max(3 * b // 10, b - (b / 250))
if x > y:
    print('Misha')
elif x < y:
    print('Vasya')
else:
    print('Tie')