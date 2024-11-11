import sys
sys.setrecursionlimit(10000)


def initRMQ(n, D):
    n_ = 1

    while n_ < n:
        n_ *= 2

    for i in range(2*n_ - 1):
        D.append(2147483647)

    return n_


def update(k, a):
    k += n_ - 1
    D[k] = a
    while k > 0:
        k = int((k - 1) / 2)
        D[k] = min(D[k*2 + 1], D[k*2 + 2])


def findMin(a, b):
    return query(a, b + 1, 0, 0, n)


def query(a, b, k, l, r):
    #print('q', a, b, k, l, r)
    if r <= a or b <= l:
        return 2147483647

    if a <= l and r <= b:
        return D[k]

    vl = query(a, b, k*2 + 1, l, int((1 + r)/2))
    vr = query(a, b, k*2 + 2, int((1 + r)/2), r)

    return min(vl, vr)


if __name__ == '__main__':
    n, q = map(int, input().split())

    D = []
    n_ = initRMQ(n, D)

    for _ in range(q):
        #print(D)
        c, x, y = map(int, input().split())

        if c == 0:
            update(x, y)

        else :
            print(findMin(x, y))

