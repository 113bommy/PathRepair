import math


def solve():
    n, k, x = map(int, input().split())
    a = list(map(int, input().split()))

    a.sort()

    v = []
    for i in range(n - 1):
        if a[i + 1] - a[i] > x:
            avg = (a[i + 1] + a[i]) // 2
            if a[i + 1] - avg > x or avg - a[i] > x:
                m = (a[i + 1] - a[i]) // x
                if a[i + 1] - (m * x + a[i]) > x:
                    m += 1
            else:
                m = 1

            v.append(m)
    v.sort()
    for i in range(len(v)):
        if k - v[i] >= 0:
            k -= v[i]
        else:
            return len(v) - i + 1

    return 1


if __name__ == '__main__':
    print(solve())
