h, w = map(int, input().split())
rb = [['#'] * (w + 2)]
a = rb + [list('#' + input() + '#') for _ in range(h)] + rb
p = [(i, j) for i in range(1, h + 1) for j in range(1, w + 1) if a[i][j] == '#']
d = (-1, 0), (1, 0), (0, -1), (0, 1)
r = -1
while p:
    r += 1
    s = []
    for i, j in p:
        for di, dj in d:
            di += i
            dj += j
            if a[di][dj] == '.':
                a[di][dj] = '#'
                s.append((di, dj))
    p = s
print(r)