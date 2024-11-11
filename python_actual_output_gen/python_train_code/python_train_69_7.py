import sys
sys.setrecursionlimit(100)

n = input()
k = int(input())
m = {}


def doit(n, k):
    if len(n) == 0:
        return k == 0
    d = int(n[0])
    if (n, k) not in m:
        ret = 0
        for i in range(d + 1):
            if i == d:
                ret += doit(n[1:], k - 1 if i > 0 else k)
            else:
                ret += doit('9' * (len(n) - 1), k - 1 if i > 0 else k)
        m[(n, k)] = ret
    return m[(n, k)]


print(doit(n, k))
