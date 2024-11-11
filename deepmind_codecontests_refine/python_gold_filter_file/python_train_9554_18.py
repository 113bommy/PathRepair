H, W, M = map(int, input().split())

h = [0] * H
w = [0] * W
boms = set()

for _ in range(M):
    x, y = map(int, input().split())
    h[x - 1] += 1
    w[y - 1] += 1
    boms.add((x, y))

h_max = max(h)
w_max = max(w)

h_idx = [x + 1 for x, y in enumerate(h) if y == h_max]
w_idx = [x + 1 for x, y in enumerate(w) if y == w_max]

minus = -1
for x in h_idx:
    for y in w_idx:
        if not (x, y) in boms:
            minus = 0
            break

print(h_max + w_max + minus)