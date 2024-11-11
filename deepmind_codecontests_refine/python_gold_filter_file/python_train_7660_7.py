n = int(input())
s = input().split()
z = 0
flag = 0
c = 0
for x in s:
    e = int(x)
    if e == 0:
        if z == 0:
            for i in range(c, 0, -1):
                print(i, end=" ")
        else:
            for i in range(1, (c + 1) // 2 + 1):
                print(i, end=" ")
            for i in range(((c + 1) // 2) - (c % 2), 0, -1):
                print(i, end=" ")
        if flag == 0:
            z += 1
            flag = 1
        c = 0
        print("0", end=" ")
    else:
        c += 1
        flag = 0
for i in range(1, c + 1):
    print(i, end=" ")