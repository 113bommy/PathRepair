n, m, a, b = map(int, input().strip().split(' '))
s1 = n * a
if n // m == 0:
    s2 = b
    print(s2)
else:
    s2 = (n // m) * b + (n % m) * a
    s3 = ((n // m) + 1) * b
    print(min(s1, s2, s3))