n, m, Sx, Sy = map(int, input().split())
print(Sx, Sy)
flag = False
for i in range(1, Sx):
    print(i, Sy)

for i in range(Sx+1, n+1):
    print(i, Sy)


for i in range(1, Sy):
    if flag:
        for j in range(1, n+1):
            print(j, i)
        flag = False
    else:
        for j in range(n, 0, -1):
            print(j, i)
        flag = True

for i in range(Sy+1, m+1):
    if flag:
        for j in range(1, n+1):
            print(j, i)
        flag = False
    else:
        for j in range(n, 0, -1):
            print(j, i)
        flag = True
