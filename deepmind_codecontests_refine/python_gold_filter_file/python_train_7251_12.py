n, s = map(int, input().split())
lx = 0

h, m = map(int, input().split())
nx = h * 60 + m
if nx - s - 1 >= 0:
    print(0, 0)
else:
    lx = nx + 1
    for i in range(1,n):
        h, m = map(int, input().split())
        nx = h * 60 + m
        if lx + 2*s < nx:
            print((lx + s) // 60, (lx + s) % 60)
            break
        lx = nx + 1
    else:
        print((lx + s) // 60, (lx + s) % 60)