N = int(input())
XY = [tuple(map(int, input().split())) for _ in range(N)]
R = [abs(x-y)&1 for x, y in XY]
if not all(R[0] == r for r in R[1:]):
    print(-1)
    exit()
RM = max(abs(x)+abs(y) for x, y in XY)
D = [1 << i for i in range(32, -1, -1)]
if RM & 1 == 0:
    D.append(1)
W = ["" for _ in range(N)]
for d in D:
    for i in range(N):
        x, y = XY[i]
        if abs(x) > abs(y):
            if x > 0:
                x -= d
                W[i] += "U"
            else:
                x += d
                W[i] += "D"
        else:
            if y > 0:
                y -= d
                W[i] += "R"
            else:
                y += d
                W[i] += "L"
        XY[i] = (x, y)
print(len(D))
print(*D)
print(*W, sep="\n")