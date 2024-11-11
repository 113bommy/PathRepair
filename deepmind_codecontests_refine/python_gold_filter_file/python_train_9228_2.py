n = int(input())
way = list(map(int, input().split()))
i, f = 0, 0
while i + 1 < n and abs(way[i] - way[i + 1]) == 1:
    i += 1
if i == n - 1:
    y = 10 ** 9
else:
    y = abs(way[i] - way[i + 1])
i = 0
while i + 1 < n and f == 0 and y != 0:
    if abs(way[i] - way[i + 1]) == 1:
        if (way[i] - 1) // y != (way[i + 1] - 1) // y:
            f = 1
    elif y != abs(way[i] - way[i + 1]):
        f = 1
    i += 1
if f == 1 or y == 0:
    print('NO')
else:
    print('YES')
    print(10 ** 9, y)