from collections import deque
H, W = map(int, input().split())
ch, cw = map(int, input().split())
dh, dw = map(int, input().split())
ch, cw, dh, dw = ch-1, cw-1, dh-1, dw-1
s = [input() for _ in range(H)]

d = [[-1]*W for _ in range(H)]

que = deque([[cw, ch, 0]])
while que:
    x, y, cost = que.popleft()
    if d[y][x]==-1 or d[y][x]>cost:
        d[y][x] = cost
        for dx in range(-2, 3):
            for dy in range(-2, 3):
                nx, ny = x+dx, y+dy
                if 0<=nx<W and 0<=ny<H and s[ny][nx]!='#':
                    if abs(dx)+abs(dy) == 1:
                        que.append([nx, ny, cost])
                    else:
                        que.append([nx, ny, cost+1])  
print(d[dh][dw])

