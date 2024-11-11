import sys


# inf = open('input.txt', 'r')
# reader = (map(int, line.split()) for line in inf)
reader = (map(int, s.split()) for s in sys.stdin)

n, sx, sy = next(reader)
left = right = up = down = 0
for _ in range(n):
    xi, yi = next(reader)
    if xi < sx:
        left += 1
    elif xi > sx:
        right += 1
    if yi > sy:
        up += 1
    elif yi < sy:
        down += 1
locs = [left, right, up, down]
idx = max(range(4), key=locs.__getitem__)
dx, dy = [(-1, 0), (1, 0), (0, 1), (0, -1)][idx]
print(locs[idx])
print(sx+dx, sy+dy)
    
# inf.close()
