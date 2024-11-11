H, W = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))
colors = []
for color in range(1, N + 1):
    for j in range(a[color - 1]):
        colors.append(str(color))
canvas = []
for i in range(H):
    if i % 2 == 0:
        canvas.append(colors[i * W: i * W + W])
    else:
        canvas.append(colors[i * W + W - 1: i * W - 1: -1])
for line in canvas:
    print(''.join(line))