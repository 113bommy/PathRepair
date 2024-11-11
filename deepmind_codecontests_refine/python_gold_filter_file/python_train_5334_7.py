t = int(input())
for _ in range (0, t):
    a, b, c, d = map(int, input().split())
    x, y, x1, y1, x2, y2 = map(int, input().split())
    diff_hor = x + b - a
    diff_ver = y + d - c
    if (x1 == x2 and (a > 0 or b > 0)) or (y1 == y2 and (c > 0 or d > 0)) or diff_hor < x1 or diff_hor > x2 or diff_ver < y1 or diff_ver > y2:
        print('no')
    else:
        print('yes')
