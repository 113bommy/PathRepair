arr = [list(map(int, input().split())) for _ in range(4)]

flag = False
for i in range(4):
    f = False
    if arr[i][3] == 1:
        s = sum([arr[i][j] for j in range(3)]) + arr[(i+2)%4][1] + arr[(i+1)%4][0] + arr[(i+3)%4][2]
        if s > 0:
            f = True

    if f:
        flag = True
        break

if flag:
    print("YES")
else:
    print("NO")
