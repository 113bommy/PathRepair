l, r = map(int, input().split())
masks = []
for i in range(64, -1, -1):
    if (1 << i) > r:
        continue
    masks.append(1 << i)
    x, y = 0, 0
    for k in masks:
        if x < y:
            x += k
        else:
            y += k
    for j in range(64, -1, -1):
        if ((x >> j) & 1) or ((y >> j) & 1):
            continue
        if x + (1 << j) < r:
            x += (1 << j)
        if y + (1 << j) < r:
            y += (1 << j)
    if min(x, y) < l or max(x, y) > r:
        masks.pop()
print(sum(masks))