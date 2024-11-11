p = [list(map(int, input().split())) for i in range(4)]
log = False
for i in range(4):
    if p[i][3] == 1 and (p[i - 1][0] == 1 or p[(i + 1) % 4][2] + p[(i + 2) % 4][1] + p[i][1] + p[i][0] + p[i][2] > 0):
        log = True
if log:
    print("YES")
else:
    print("NO")

