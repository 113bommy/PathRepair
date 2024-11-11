a, b = input(), input()
a, b = ('abcdefgh'.find(a[0]), int(a[1]) - 1), ('abcdefgh'.find(b[0]), int(b[1]) - 1)
t = [[0] * 8 for i in range(8)]
t[a[0]] = [1] * 8
for i in range(8):
    t[i][a[1]] = 1
for i, j in [(1, 2), (1, -2), (2, 1), (2, -1), (-1, 2), (-1, -2), (-2, 1), (-2, -1)]:
    x, y = b[0] + i, b[1] + j
    if -1 < x < 8 and -1 < y < 8:
        t[y][x] = 1
    x, y = a[0] + i, a[1] + j
    if -1 < x < 8 and -1 < y < 8:
        t[y][x] = 1
print(sum(i.count(0) for i in t) - 1)