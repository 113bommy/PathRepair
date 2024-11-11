t = int(input())
c = []
for i in range(t):
    c.append([])
    k = (input()).split(" ")
    for j in range(4):
        c[i].append(int(k[j]))
for i in range(t):
    if (c[i][0] != c[i][2]) and (c[i][1] != c[i][3]):
        print(abs(c[i][3] - c[i][1]) + abs(c[i][2] - c[i][0]) + 2)
    else:
        print(abs(c[i][3] - c[i][1]) + abs(c[i][2] - c[i][0]))
