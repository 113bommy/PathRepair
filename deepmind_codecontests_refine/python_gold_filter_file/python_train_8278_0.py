import sys
sys.stderr = sys.stdout


def cookies(n, k, A, B):
    def cfn(a, b):
        q, r = divmod(b, a)
        return q, a - r, a

    L = sorted(cfn(A[i], B[i]) for i in range(n))
    c = 0
    p = 0
    q = 0
    for ci, pi, ai in L:
        if ci == c:
            p += pi
            q += ai
            continue
        if p > k:
            return c
        k -= p
        c += 1
        dk = q * (ci - c)
        if dk >= k:
            c += k // q
            return c
        k -= dk
        c = ci
        p = q + pi
        q += ai

    if p > k:
        return c
    k -= p
    c += 1
    c += k // q
    return c


def main():
    n, k = readinti()
    A = readintl()
    B = readintl()
    print(cookies(n, k, A, B))

##########

def readint():
    return int(input())


def readinti():
   return map(int, input().split())


def readintt():
   return tuple(readinti())


def readintl():
   return list(readinti())


def readinttl(k):
    return [readintt() for _ in range(k)]


def readintll(k):
    return [readintl() for _ in range(k)]


def log(*args, **kwargs):
    print(*args, **kwargs, file=sys.__stderr__)


if __name__ == '__main__':
    main()
