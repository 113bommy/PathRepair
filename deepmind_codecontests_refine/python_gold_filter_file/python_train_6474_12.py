M = int(1e9 + 7)
n, m = map( int, input().split( ) )
a, b = 1, 2
while m:
    if m & 1:
        a *= b
    b *= b
    m //= 2
    a %= M
    b %= M
a += M - 1
a %= M
oa = a
b = 1
while n:
    if n & 1:
        b *= a
    a *= a
    n //= 2
    a %= M
    b %= M

print( b % M )
