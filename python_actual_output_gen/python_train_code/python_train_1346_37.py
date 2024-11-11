l = input().split()
n = int(l[0])
m = int(l[1])
k = ["." for i in range(m)]
a = [k[:] for i in range(n)]
for i in range(n):
    for x in range(m):
        if i % 2 == 0:
            a[i][x] = "#"
        if i % 4 == 1:
            a[i][-1] = "#"
        if i % 4 == 3:
            a[i][0] = "#"
for i in range(n):
    for v in range(m):
        print(a[i][v], end=" ")
    print()
