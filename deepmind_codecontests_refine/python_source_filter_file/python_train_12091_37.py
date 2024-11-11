n, m, k = map(int, input().split())
a = list(map(int, input().split()))

a.sort(reverse=True)

if n == 1 or k >= m:
    print(a[0] * k)
else:
    print((a[0] * k + a[1]) * m // (k + 1) + a[0] * (m % (k + 1)))