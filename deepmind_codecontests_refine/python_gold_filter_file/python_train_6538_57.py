H,W = map(int, input().split())
B = [list(input()) for i in range(H)]

l = []

for i in range(H):
    for j in range(W):
        if B[i][j] == '#':
            l.append((i,j))

def a(l):
    n = []
    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for y, x in l:
        for dy, dx in d:
            ny = y + dy
            nx = x + dx
            if 0 <= ny < H and 0 <= nx < W and B[ny][nx] == '.':
                B[ny][nx] = '#'
                n.append((ny, nx))
    return n

ans = 0
while len(l) != 0:
    l = a(l)
    ans += 1
print(ans-1)