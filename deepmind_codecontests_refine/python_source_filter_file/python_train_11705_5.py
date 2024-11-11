import sys
import math
a, b = map(int,sys.stdin.readline().split())
def check(x,z):
    # if not (abs(x-round(x)) < 1e-6 and 0 < x < z):
    #     print("no", x, z)
    return abs(x-round(x)) < 1e-6 and 0 < x < z
def solve2(a,b):
    for ax in range(1,a):
        for ay in range(1,a):
            if not ax**2+ay**2 == a**2: continue
            bx, by = ay/a*b, -ax/a*b
            if not (check(bx,b) and check(-by,b)): continue
            bx, by = round(bx), round(by)
            cx = bx - ax
            cy = ay - by
            c = math.sqrt(a**2+b**2)
            if not (check(cx,c) and check(cy,c)): continue
            print("YES")
            print(0, 0)
            print(ax, ay)
            print(bx, by)
            return
    print("NO")

def solve(a,b):
    for ax in range(1,a):
        ay = math.sqrt(a**2 - ax**2)
        # print('ay', a, ax, ay)
        if not check(ay,a): continue
        ay = round(ay)

        by = b/a*ax
        # print('by', ax, ay, by)
        if not check(by,b): continue
        by = round(by)


        bx = math.sqrt(b**2 - by**2)
        # print('bx', ax, ay, by, bx)
        if not check(bx,b): continue
        bx = round(bx)

        cx = bx - ax
        cy = ay + by
        # print('c', cx, cy)
        if not (0 != cx and 0 != cy): continue

        print("YES", a, b)
        # print("YES")
        print(0, 0)
        print(ax, ay)
        print(bx, -by)
        break
    else:
        # pass
        print("NO")
# for a in range(1,20):
#     for b in range(1,20):
#         solve2(a,b)
solve2(a,b)