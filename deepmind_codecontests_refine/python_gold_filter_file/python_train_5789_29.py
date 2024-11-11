a = []
for i in range(4):
    tmp = list(map(int, input().split()))
    a.append(tmp)

crash = False

for i in range(4):
    for j in range(4):
        if a[i][j] == 1 and j < 3:
            if a[i][3] == 1:
                crash = True
                break
            elif j == 0:
                if a[i - 1 if i - 1 > -1 else 3][3] == 1:
                    crash = True
                    break
            elif j == 1:
                if a[i + 2 if i < 2 else i - 2][3] == 1:
                    crash = True
                    break
            elif j == 2:
                if a[i + 1 if i + 1 < 4 else 0][3] == 1:
                    crash = True
                    break

if crash:
    print("YES")
else:
    print("NO")