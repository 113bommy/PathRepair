n = int(input())
y = 0
maxlen = 20000
for i in range(n):
    raw = input().split()
    cur = int(raw[0])
    dir = raw[1]
    if y == 0 and dir != 'South':
        print('NO')
        quit()
    if y == maxlen and dir != 'North':
        print('NO')
        quit()
    if (dir == 'South'):
        y += cur
    elif (dir == 'North'):
        y -= cur
    if (y < 0 or y > maxlen):
        print('NO')
        quit()
if y == 0:
    print('YES')
else:
    print('NO')