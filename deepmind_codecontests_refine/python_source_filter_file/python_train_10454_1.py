def f(k):
    if k == 1: return (1, 0, 0, 0, 0)
    if k == 2: return (0, 1, 0, 0, 0)
    if k == 3: return (1, 1, 1, 0, 0)
    a, b = 1, 1
    for i in range(k - 3): a, b = b, a + b
    c = a
    d = e = 0
    for i in range(k - 3): d, e = e, d + e + int(i % 2 == 0)
    return (a, b, c, d, e)

def r(a, i, n):
    if n == 1:
        if a == 'BB': return 'B'
        if a == 'BA': return 'A'
        if a == 'CB': return 'C'
        return False
    if i == 0:
        if a == 'BB': return 'B' * n
        if a == 'BA': return 'B' * (n - 1) + 'A'
        if a == 'CB': return 'C' + 'B' * (n - 1)
    x = 'AC' * i
    n -= len(x)
    if n < 0: return False
    if a[0] == 'B':
        if a[1] == 'B': return x + 'C' * n
        return x + 'A' * n
    else:
        if a[1] == 'B': return 'C' * n + x
        n -= 1
        if n < 0: return False
        return 'C' + x + 'A' * n

def g(a, b, i, j, n, m):
    a, b = r(a, i, n), r(b, j, m)
    if a and b:
        print(a)
        print(b)
        return True
    return False

def h():
    k, x, n, m = map(int, input().split())
    t = f(k)
    for i in range(n // 2 + 1):
        for j in range(m // 2 + 1):
            if x == t[0] * i + t[1] * j:
                print('AC' * i + 'B' * (n - 2 * i))
                print('AC' * j + 'B' * (m - 2 * j))
                return
    for i in range((n + 1) // 2):
        for j in range((m + 1) // 2):
            y = x - (t[0] * i + t[1] * j)
            if y == t[2] and g('BA', 'CB', i, j, n, m): return
            if y == t[3] and g('BB', 'CA', i, j, n, m): return
            if y == t[4] and g('CB', 'BA', i, j, n, m): return
            if y == t[2] + t[3] and g('BA', 'CA', i, j, n, m): return
            if y == t[3] + t[4] and g('CB', 'BA', i, j, n, m): return
            if y == t[2] + t[3] + t[4] and g('CA', 'CA', i, j, n, m): return
    print('Happy new year!')
h()