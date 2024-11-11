h, w, n = map(int, input().split())

ps = [[] for i in range(h)]
blocks = set()
for i in range(n):
    x, y = map(lambda x: int(x)-1, input().split())
    if x < y:
        continue
    ps[y].append(x)
    blocks.add((x, y))
x, y = (0, 0)
cands = [w]
while y < h:
    if (x+1, y) in blocks:
        # 高橋君は移動できなければ = 障害物に移動すると即死
        cands.append(x+1)
        break
    else:
        x += 1
        ps[y] = [p for p in ps[y] if p > x]
        if ps[y]:
            cands.append(min(ps[y]))
        while (x, y+1) in blocks and (x+1, y) not in blocks and x < w:
            x += 1
    
    if (x, y+1) in blocks:
        break
    y += 1
print(min(cands))
