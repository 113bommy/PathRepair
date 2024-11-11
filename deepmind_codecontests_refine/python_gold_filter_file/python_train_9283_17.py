def inp(dtype=str, strip=True):
    s = input()
    res = [dtype(p) for p in s.split()]
    res = res[0] if len(res) == 1 and strip else res
    return res


def problem1():
    n = inp(int)
    a = inp(int, strip=False)
    m = inp(int)
    b = inp(int, strip=False)

    union = set(a + b)

    for k1 in a:
        for k2 in b:
            if k1 + k2 not in union:
                print(k1, k2)
                return


def problem2():
    n = inp(int)
    a = inp(int, strip=False)

    res = 0
    has0 = False
    negs = 0
    for k in a:
        if k < 0:
            negs += 1
        if k == 0:
            has0 = True
            res += 1
        else:
            res += abs(k) - 1

    if negs % 2 == 1 and not has0:
        res += 2

    print(res)


def problem3():
    n = int(input().strip())
    if n % 2 == 0:
        print('NO')
    else:
        a = [0 for _ in range(2 * n)]
        for i in range(2 * n):
            offset = n if i % 4 in [1, 2] else 0
            pos = offset + (i // 2)
            # print(pos)
            a[pos] = i + 1
        print('YES')
        print(' '.join([str(el) for el in a]))


def problem4():
    pass


if __name__ == '__main__':
    # problem1()
    # problem2()
    problem3()
    # problem4()
