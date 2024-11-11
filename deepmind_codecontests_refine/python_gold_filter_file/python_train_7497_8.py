import sys
sys.setrecursionlimit(10000)


def initRMQ(n):
    n_ = 1

    while n_ < n:
        n_ *= 2

    D = []
    for _ in range(2*n_ - 1):
        D.append(0)

    return n_, D


def update(k, a):
    k += n_ - 1
    D[k] += a
    while k > 0:
        k = int((k - 1) / 2)
        D[k] = D[k*2 + 1] + D[k*2 + 2]


def findSum(a, b):
    return query(a, b + 1, 0, 0, n_)


def query(a, b, k, l, r):
    #print('q', a, b, k, l, r)
    if r <= a or b <= l:
        return 0

    if a <= l and r <= b:
        return D[k]

    vl = query(a, b, k*2 + 1, l, int((l + r)/2))
    vr = query(a, b, k*2 + 2, int((l + r)/2), r)

    return vl + vr


if __name__ == '__main__':
    n, q = map(int, input().split())

    n_, D = initRMQ(n)

    for _ in range(q):
        #print(D)
        c, x, y = map(int, input().split())

        if c == 0:
            update(x - 1, y)

        else :
            print(findSum(x - 1, y - 1))

