t = int(input())
for i in range(t):
    n = input()
    ax, ay = map(int, input().split())
    bx, by = map(int, input().split())
    tx, ty = map(int, input().split())
    if ax != bx and ay != by:
        print(max(ax, bx) - min(ax, bx) + max(ay, by) - max(ay, by) + 2)
    elif ax == bx:
        if tx == ax and min(ay, by) < ty < max(ay, by):
            print(max(ay, by) - min(ay, by) + 2)
        else:
            print(max(ay, by) - min(ay, by))
    else:
        if ty == ay and min(ax, bx) < tx < max(ax, bx):
            print(max(ax, bx) - min(ax, bx) + 2)
        else:
            print(max(ax, bx) - min(ax, bx))
