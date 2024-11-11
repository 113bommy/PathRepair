N,K = map(int,input().split())
XY = []

for i in range(N):
    x,y = map(int,input().split())
    XY.append((x,y))


ans = float('inf')

for lx, _ in XY:
    for rx, _ in XY:
        if lx > rx:
            continue
        for _, dy in XY:
            for _, uy in XY:
                if dy > uy:
                    continue
                count = 0
                for x,y in XY:
                    if lx <= x <= rx and dy <= y <= uy:
                        count += 1
                if count >= K:
                    ans = min(ans,(rx-lx)*(uy-dy))
print(ans)