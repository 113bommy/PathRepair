x = list(map(int, input().split(" ")))

y = []
a = []
b = []

for i in range(x[0]):
    y.append(input().split(" "))

for i in y:
    for j in i:
        b.append(list(j))

for i in range(len(b)):
    for j in range(len(b[0])):
        if b[i][j] == "*":
            a.append([i, j])
        else:
            pass

if a[0][0] != a[1][0]:
    if a[0][1] != a[1][1]:
        print(*[a[0][0]+1, a[1][1]+1])
    else:
        print(*[a[0][0]+1, a[2][1]+1])
else:
    if a[1][1] != a[2][1]:
        print(*[a[2][0]+1, a[0][1]+1])
    else:
        print(*[a[2][0]+1, a[1][1]+1])
