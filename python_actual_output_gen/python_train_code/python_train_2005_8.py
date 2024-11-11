a = []
for i in range(4):
    a.append(list(map(int, input().split())))

crash = False

for i in range(4):
    if a[i][3] == 1:
        if a[(i - 1) % 4][0] or a[(i + 2) % 4][1] or a[(i + 1) % 4][2] or sum(a[i]) > 1:
            crash = True
            break

if crash:
    print("YES")
else:
    print("NO")