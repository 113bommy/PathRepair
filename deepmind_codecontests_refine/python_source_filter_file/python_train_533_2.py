from collections import defaultdict
import sys


def input():
    return sys.stdin.readline().rstrip()


def slv():
    n = int(input())
    a = list(map(int, input().split()))
    res = []
    d = defaultdict(int)
    for i, v in enumerate(a):
        d[v] = i

    def swapR(V):
        idx_V = d[V]
        assert a[idx_V] == V
        if idx_V == V - 1:
            return
        if idx_V + 1 >= n//2:
            res.append((idx_V + 1, 1))
            exv = a[0]
            d[exv] = idx_V
            d[V] = 0
            a[idx_V], a[0] = a[0], a[idx_V]
            swapR(V)
            return

        elif idx_V == 0:
            res.append((V, 1))
            exv = a[V - 1]
            d[V] = V - 1
            d[exv] = 0
            a[0], a[V - 1] = a[V - 1], a[0]
            return

        else:
            exv = a[n - 1]
            res.append((n, idx_V + 1))
            d[exv] = idx_V
            d[V] = n - 1
            a[idx_V], a[n - 1] = a[n - 1], a[idx_V]
            swapR(V)
            return

    def swapL(V):
        idx = d[V]
        assert (a[idx] == V)
        if V == 1:
            if all(a[i] == i + 1 for i in range(n)):
                return
        if idx != n - 1:
            exv = a[n - 1]
            res.append((idx + 1, n))
            d[V] = n - 1
            d[exv] = idx
            a[idx], a[n - 1] = a[n - 1], a[idx]

        if V == 1:
            if all(a[i] == i + 1 for i in range(n)):
                return

        exv = a[V - 1]
        res.append((V, n))
        d[V] = V - 1
        d[exv] = n - 1
        a[V - 1], a[n - 1] = a[n - 1], a[V - 1]

        return

    for i in range(n//2 + 1, n):
        swapR(i)

    for i in range(n//2, 0, -1):
        swapL(i)

    assert all(a[i] == i + 1 for i in range(n))
    print(len(res))
    for u, v in res:
        print(u, v)
    return


def main():
    t = 1
    for i in range(t):
        slv()
    return


if __name__ == "__main__":
    main()
