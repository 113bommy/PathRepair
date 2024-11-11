def gcd(m, n):
    if m < n:
        m, n = n, m
    r = m % n
    while r:
        m, n = n, r
        r = m % n
    return n


def search(x, y):
    while True:
        if x == 1:
            ans.extend( [] if y == 1 else (str(y - 1) + 'B') )
            return
        if y == 1:
            ans.extend( [] if x == 1 else (str(x - 1) + 'B') )
            return
        if x < y:
            ans.append(str(y // x) + 'B')
            x, y = x, y % x
        else:
            ans.append(str(x // y) + 'A')
            x, y = x % y, y

a, b = [ int(i) for i in input().split() ]

if gcd(a, b) != 1:
    print("Impossible")
else:
    ans = []
    search(a, b)
    
    i, length = 0, len(ans)
    print(''.join(ans))