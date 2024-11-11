from math import ceil

n = int(input())
for i in range(n):
    n, x, y, d = list(map(int, input().split()))
    max_num = 10 ** 10
    if (y - x) % d == 0:
        max_num = (y - x) // d
    if y % d == 1:
        a = ceil(x / d) + (y - 1) // d
        if a < max_num:
            max_num = a
    if y % d == n % d:
        a = ceil((n - x) / d) + (n - y + 1) // d
        if a < max_num:
            max_num = a
    if max_num == 10 ** 9:
        print(-1)
    else:
        print(max_num)
