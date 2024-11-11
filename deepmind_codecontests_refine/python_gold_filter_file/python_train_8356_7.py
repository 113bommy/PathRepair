x = input()
x = int(x)
all = []
for i in range(x):
    # _  = input()
    t = input()
    # all.append([int(i) for i in t.split()])
    all.append(int(t))
for row in all:
    mark = False
    mx1, mx2,mx3= round(row/3),round(row/5),round(row/7)
    for x3 in range(mx3+1):
        for x2 in range(mx2+1):
            for x1 in range(mx1+1):
                sum = x1*3 + x2*5+ x3*7
                if sum == row:
                    print(x1,x2,x3)
                    mark = True
                    break
            if mark:
                break
        if mark:
            break
    if not mark:
        print(-1)