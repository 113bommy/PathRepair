def gcd(a, b):
    while b:
        a, b = b, a % b
    return a
 
a = input().split(' ')
b = list(a)
n = int(b[0])
m = int(b[1])
k = int(b[2])
bu = True
bul = True
if (2*n*m % k != 0):
    print('NO')
    bul = False
if bul:
    print('YES')
    print('0 0')
    d = gcd(n, k)
    ki = k // d
    ni = n // d
    if ki != 1:
        ai = 2*ni
        bi = 2*m//ki
    if ki == 1:
        ai = 2*ni
        bi =  m
    print('0 {}'.format(bi))
    print('{} 0'.format(ai))
