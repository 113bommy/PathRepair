n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)
if n < m:
    print('0/1')
elif n > m:
    print(('-' if b[0] * a[0] < 0 else '') + 'Infinity')
else:
    f = a[0] * b[0]
    gd = gcd(abs(a[0]), abs(b[0]))
    a[0] = abs(a[0]) // gd
    b[0] = abs(b[0]) // gd
    print(('-' if f < 0 else '') + str(a[0]) + '/' + str(b[0]))
