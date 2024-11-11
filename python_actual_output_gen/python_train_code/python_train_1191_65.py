for _ in range(int(input())):
    l1 = input().split()
    mark = list(map(int,l1[0:]))
    x, y, z = int(0), int(0), int(0)
    x = mark[3]
    y = mark[2]
    z = mark[1]
    print(x,y,z)
