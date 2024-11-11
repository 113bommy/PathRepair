import sys
input = sys.stdin.readline

H, W, N = map(int, input().split())
obstacles = [[] for _ in range(H+1)]
for i in range(N):
    X, Y = map(int, input().split())
    obstacles[X].append(Y)
max_y = 1
for x in range(2, H+1):
    if not obstacles[x]:
        max_y += 1
        continue
    my = min(obstacles[x])
    if max_y == my:
        print(x - 1)
        exit()
    if max_y + 1 < my:
        max_y += 1
print(H)