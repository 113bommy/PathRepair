__author__ = 'NIORLYS'


def gcd(m, n):
    if n == 0:
        return m
    return gcd(n, m % n)


n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
fractions_records = {}
max_zeros = b_zeros = 0
for i in range(n):
    if b[i] == 0:
        b_zeros += 1
        continue
    fraction = (b[i] // gcd(b[i], a[i]), a[i] // gcd(b[i], a[i]))
    if fraction in fractions_records:
        fractions_records[fraction] += 1
    else:
        fractions_records[fraction] = 1
del a, b
for key in fractions_records:
    if key[1] and fractions_records[key] > max_zeros:
        max_zeros = fractions_records[key]
print(max_zeros + b_zeros)
