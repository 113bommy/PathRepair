n = int(input())

ax, ay = map(int,input().split())
bx, by = map(int,input().split())
cx, cy = map(int,input().split())


def under_attack(a, c):

    #row, col
    if (a[0] == c[0])  or (a[1] == c[1]):
        return True

    #diag
    x, y = a[0], a[0]
    diff =0
    #while diff <= max(n-a[0], a[0]):
    #     if (x+diff, y+diff) == c or (x-diff, y-diff) == c or (x-diff, y+diff) == c or (x+diff, y-diff) == c:
    #         return True
    #     diff += 1

    return False

def get_square(p, c):
    if p[0] < c[0]:
        f = 1
    else:
        f = 2
    if p[1] < c[1]:
        x = 1
    else:
        x = 2

    return (f, x)

def is_one_square(a, b, c):
    return get_square(a, b) == get_square(a, c)

if not under_attack((ax, ay), (cx, cy)) and is_one_square((ax,ay),(bx,by), (cx,cy)):
    print("YES")
else:
    print("NO")