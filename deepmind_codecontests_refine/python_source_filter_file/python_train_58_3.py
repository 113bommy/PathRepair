t, m = map(int, input().split())
a, b = [0] * m, 1

def alloc(n):
    global b
    f = 0
    for i in range(m):
        if not a[i]:
            f += 1
            if f == n:
                a[i - n + 1:i + 1] = [b] * n
                b += 1
                return b - 1
        else:
            f = 0
    return 'NULL'

def erase(x):
    f = 0
    for i in range(m):
        if a[i] == x:
            a[i] = 0
            f += 1
    if f == 0:
        print('ILLEGAL_ERASE_ARGUMENT')

def defragment():
    f = 0
    for i in range(m):
        if f and a[i]:
            a[i - f], a[i] = a[i], 0
        elif not a[i]:
            f += 1

for i in range(t):
    c = input().split()
    if c[0] == 'alloc':
        print(alloc(int(c[1])))
    elif c[0] == 'erase':
        erase(int(c[1]))
    else:
        defragment()