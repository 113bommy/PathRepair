import sys
def rs(): return sys.stdin.readline().rstrip()
def ri(): return int(sys.stdin.readline())
def ria(): return list(map(int, sys.stdin.readline().split()))
def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')


def can(n, k, a, x):
    # testing odd indices
    m1 = []
    for i in range(n):
        if len(m1) % 2 == 0:
            m1.append(a[i])
        else:
            if a[i] <= x:
                m1.append(a[i])

    # testing even indices
    m2 = []
    for i in range(n):
        if len(m2) % 2 == 1:
            m2.append(a[i])
        else:
            if a[i] <= x:
                m2.append(a[i])

    return len(m1) >= k or len(m2) >= k


def solve(n, k, a):
    lo = 1
    hi = max(a)
    while hi > lo:
        mid = (lo + hi) // 2
        if can(n, k, a, mid):
            hi = mid
        else:
            lo = mid + 1

    return hi


def main():
    n, k = ria()
    a = ria()
    wi(solve(n, k, a))


if __name__ == '__main__':
    main()
