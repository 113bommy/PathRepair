q = int(input())
for i in range(q):
    s1 = 0
    s2 = 10**100
    s3 = 0
    n, a, b = map(int, input().split())
    s1 = n * a
    if n % 2 == 0:
        s2 = n // 2 * b
    s3 += (n // 2) * b
    s3 += n%2 * a
    print(min(s1, s2, s3))