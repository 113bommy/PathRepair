def gcd(a, b):
    c = a % b
    return gcd(b, c) if c else b

n, m = map(int, input().split())
p, q = input(), input()
a, b = p.find(' '), q.find(' ')
p, q = int(p) if a < 0 else int(p[: a]), int(q) if b < 0 else int(q[: b])

if n > m: print('-Infinity' if p * q < 0 else 'Infinity')
elif n < m: print('0/1')
else:
    s = gcd(p, q)
    print(str(p // s) + '/' + str(q // s))