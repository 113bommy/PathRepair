(x, y, z, t1, t2, t3) = map(int, input().split())


if 2 * t3 + t2 * (abs(z - x) + abs(x - y)) <= t1 * abs(x - y):
    print("YES")
else:
    print("NO")

