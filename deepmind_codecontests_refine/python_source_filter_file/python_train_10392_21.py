N = int(input())
XY = [list(map(int, input().split())) for _ in range(N)]
MOD = sum(XY[0]) % 2

for x, y in XY:
    if MOD != (x + y) % 2:
        print(-1)
        exit()

m = 33 - MOD
print(m)
D = [2 ** i for i in range(31, -1, -1)]
if MOD == 0:
    D.append(1)

print(" ".join(map(str, D)))
for x, y in XY:
    w = ""
    for d in D:
        if x + y >= 0 and x - y >= 0:
            w += "R"
            x -= d
        elif x + y > 0 and x - y <= 0:
            w += "D"
            y += d
        elif x + y <= 0 and x - y > 0:
            w += "U"
            y -= d
        else:
            w += "L"
            x -= d

    print(w)
