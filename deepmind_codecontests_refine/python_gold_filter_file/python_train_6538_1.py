h, w = map(int, input().split())
a = [['#'] * (w + 2)] * 2
a[1: 1] = (['#'] + list(input()) + ['#'] for _ in range(h))
d = (-1, 0), (1, 0), (0, -1), (0, 1)

step = [(i, j) for i in range(1, h + 1) for j in range(1, w + 1)
       if a[i][j] == '#']

def next_step():
    r = []
    for i, j in step:
        for di, dj in d:
            di += i
            dj += j
            if a[di][dj] == '.':
                a[di][dj] = '#'
                r.append((di, dj))
    return r

n = h * w - len(step)
r = 0
while n:
    r += 1
    step = next_step()
    n -= len(step)
print(r)
