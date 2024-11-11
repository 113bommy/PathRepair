t = int(input())


def left_edge():
    return (x + d - 1) // d + y // d


def right_edge():
    return (n - x + d - 1) // d + (n - y) // d


for _ in range(t):
    n, x, y, d = map(int, input().split())
    n -= 1
    x -= 1
    y -= 1

    if x % d == y % d:
        print(abs(x - y) // d)
        continue

    if y % d == 0 and (n - y) % d == 0:
        print(max(left_edge(), right_edge()))
        continue

    if y % d == 0:
        print(left_edge())
        continue

    if (n - y) % d == 0:
        print(right_edge())
        continue

    print(-1)
