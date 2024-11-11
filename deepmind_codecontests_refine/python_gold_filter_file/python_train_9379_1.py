def y(x1, y1, x2, y2, i):
    n = len(x1)
    if i == 0:
        return [int(max(x1[i + 1:])), int(max(y1[i + 1:])), int(min(x2[i + 1:])), int(min(y2[i + 1:]))]
    elif i == n - 1:
        return [int(max(x1[:i])), int(max(y1[:i])), int(min(x2[:i])), int(min(y2[:i]))]
    else:
        return [int(max(max(x1[:i]), max(x1[i + 1:]))), int(max(max(y1[:i]), max(y1[i + 1:]))), int(min(min(x2[:i]), min(x2[i + 1:]))), int(min(min(y2[:i]), min(y2[i + 1:])))]
n = int(input())
x1 = [0] * n
y1 = [0] * n
x2 = [0] * n
y2 = [0] * n
for i in range(n):
    x1[i], y1[i], x2[i], y2[i] = map(int, input().split())
ix1 = y(x1, y1, x2, y2, x1.index(max(x1)))
iy1 = y(x1, y1, x2, y2, y1.index(max(y1)))
ix2 = y(x1, y1, x2, y2, x2.index(min(x2)))
iy2 = y(x1, y1, x2, y2, y2.index(min(y2)))
if ix1[2] - ix1[0] >= 0 and ix1[3] - ix1[1] >= 0:
    print(ix1[0], ix1[1])
elif ix2[2] - ix2[0] >= 0 and ix2[3] - ix2[1] >= 0:
    print(ix2[0], ix2[1])
elif iy1[2] - iy1[0] >= 0 and iy1[3] - iy1[1] >= 0:
    print(iy1[0], iy1[1])
elif iy2[2] - iy2[0] >= 0 and iy2[3] - iy2[1] >= 0:
    print(iy2[0], iy2[1])