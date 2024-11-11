from functools import cmp_to_key


def get_max_from(data, x):
    for i, c in enumerate(data):
            if c[0] < x:
                data.pop(i)
                return c[1]

    return None


def test(data0, data1, x):
    total = 0

    while True:
        max_m = get_max_from(data0, x)
        if max_m is not None:
            x += max_m
            total += 1
        else:
            return total

        max_m = get_max_from(data1, x)
        if max_m is not None:
            x += max_m
            total += 1
        else:
            return total


if __name__ == '__main__':
    n, x = map(int, input().split())

    data0 = []
    data1 = []

    for i in range(n):
        d = tuple(map(int, input().split()))
        t = d[1], d[2]

        if d[0] == 0:
            data0.append(t)
        else:
            data1.append(t)

    cmp = lambda a, b: b[1] - a[1]

    data0.sort(key=cmp_to_key(cmp))
    data1.sort(key=cmp_to_key(cmp))

    d0 = data0.copy()
    d1 = data1.copy()

    print(max(test(d0, d1, x), test(data1, data0, x)))