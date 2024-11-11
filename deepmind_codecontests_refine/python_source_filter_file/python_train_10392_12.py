import sys

N = int(input())
XY = list()
for i in range(N):
    XY.append(list(map(int, input().split(" "))))

eo = sum(XY[0]) % 2
for xy in XY:
    if (sum(xy) % 2 != eo):
        print(-1)
        os.exit()

m = 40 - eo
print(m)
D = [2 ** i for i in range(38, -1, -1)]
if eo == 0:
    D.append(1)

print(" ".join(map(str, D)))
for x, y in XY:
    w = ""
    for i in range(m):
        if 0 <= x - y and 0 <= x + y:
            w += "R"
            x -= D[i]
        elif 0 > x - y and 0 <= x + y:
            w += "U"
            y -= D[i]
        elif 0 <= x - y and 0 > x + y:
            w += "D"
            y += D[i]
        else:
            w += "L"
            x += D[i]
    print(w)
