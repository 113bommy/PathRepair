f = list(zip(*(list(input()) for _ in range(8))))
res = (1000000, 'X')
for line in f:
    w = line.count('W')
    b = line.count('B')
    if not w and not b:
        continue
    if (w > 0) != (b > 0):
        c = 'W' if w else 'B'
        idx = line.index(c)
        if c == 'B':
            idx = line[::-1].index(c)
        idx = idx * 2
        if c == 'B':
            idx += 1
        cur = (idx, c)
        res = min(res, cur)
        continue
    for i in range(8):
        if line[i] == 'B':
            break
        if line[i] == 'W':
            cur = (i * 2, 'W')
            res = min(res, cur)
            break
    for i in range(8):
        if line[7 - i] == 'W':
            break
        if line[7 - i] == 'B':
            cur = (i * 2 + 1, 'B')
            res = min(res, cur)
            break
print('A' if res[1] == 'W' else 'B')
