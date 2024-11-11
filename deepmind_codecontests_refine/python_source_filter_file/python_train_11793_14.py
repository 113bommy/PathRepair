from math import asin, pi

n, R, r = map(int, input().split())

if n == 1 and r <= R:
    print('YES')
elif 2 * r >= R:
    print('NO')
elif (pi / asin(r / (R - r))) + 10 ** -6 >= n:
    print('YES')
else:
    print('NO')
