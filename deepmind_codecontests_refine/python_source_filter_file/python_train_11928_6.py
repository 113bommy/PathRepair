n = int(input())
up = -10 ** 9
down = -up
for i in range(n):
    c, d = map(int, input().split())
    if d == 1:
        up = max(1900, up)
    else:
        down = min(1899, down)
    up += c
    down += c
if down < up:
    print('Impossible')
elif up >= 10 ** 9:
    print('Infinity')
else:
    print(down)
