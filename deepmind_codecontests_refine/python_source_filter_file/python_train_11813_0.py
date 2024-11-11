m,n = map(int,input().split())
b = []
for i in range(m):
    b.append(list(map(int,input().split())))
a = [[1 for i in range(n)] for i in range(m)]
for i in range(m):
    for j in range(n):
        if b[i][j] == 0:
            for x in range(n):
                a[i][x] = 0
            for x in range(m):
                a[x][j] = 0
tmp = [[1 for i in range(n)] for i in range(m)]
for i in range(m):
    for j in range(n):
        if a[i][j] == 1:
            for x in range(n):
                tmp[i][x] = 1
            for x in range(m):
                tmp[x][j] = 1
if tmp == b:
    print("YES")
    for i in range(m):
        print(*a[i])
else:
    print("NO")