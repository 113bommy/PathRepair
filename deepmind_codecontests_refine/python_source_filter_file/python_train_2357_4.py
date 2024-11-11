n = int(input())
a = int(input())
b = int(input())
ax, bx = 4, 2
x = 0
z = False
if a*2+b < n//2:
    print(1)
elif a*2+b == n:
    print(2)
elif a >= b:
    while ax >= 0 and bx >= 0:
        if ax == bx == 0:
            print(x)
            exit()
        for i in range(ax, -1, -1):
            for j in range(bx, -1, -1):
                # print(i ,j)
                if (a*i)+(b*j) <= n:
                    # print('yes')
                    ax -= i
                    bx -= j
                    x += 1
                    z = True
                    break
            if z:
                z = not z
                break
else:
    while ax >= 0 and bx >= 0:
        if ax == bx == 0:
            print(x)
            exit()
        for i in range(bx, -1, -1):
            for j in range(ax, -1, -1):
                print(i ,j)
                if (a*j)+(b*i) <= n:
                    print('yes')
                    ax -= j
                    bx -= i
                    x += 1
                    z = True
                    break
            if z:
                z = not z
                break
