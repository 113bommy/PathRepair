from math import ceil, sqrt


def total_days(x, d_):
    return x + ceil(d_/(x + 1))


t = int(input())

for i in range(t):
    n, d = map(int, input().split())

    x_min = sqrt(d) - 1
    min_days_required = total_days(x_min, d)
    if min_days_required > d:
        print("NO")
    else:
        print("YES")
