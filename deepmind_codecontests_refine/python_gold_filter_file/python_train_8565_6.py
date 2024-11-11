def read_generator():
    while True:
        tokens = input().split(' ')
        for t in tokens:
            yield t

reader = read_generator()

def readword():
    return next(reader)

def readint():
    return int(next(reader))

def readfloat():
    return float(next(reader))

def readline():
    return input()

def solve(a, b, n):
    l = 1
    r = 10 ** 9

    while r - l > 1:
        t = (l + r) // 2
        if possible(a, b, n, t):
            r = t
        else:
            l = t

    if possible(a, b, n, l):
        return l
    return r


def possible(a, b, n, t):
    s = 0
    for i in range(n):
        if a[i] > t:
            s += b[i]
    return s <= t

tests = readint()

for t in range(tests):
    n = readint()
    a = [readint() for _ in range(n)]
    b = [readint() for _ in range(n)]
    print(solve(a, b, n))