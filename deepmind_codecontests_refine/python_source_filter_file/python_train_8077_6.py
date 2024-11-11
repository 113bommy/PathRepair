a, b = map(int, input().strip().split())

x = 1
while (a > 0 or b > 0):
    a -= x
    x += 1
    b -= x
    x += 1

if (a < 0):
    print('Vladik')
else:
    print('Valera')