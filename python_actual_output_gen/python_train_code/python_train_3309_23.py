n, a, b = map(int, input().split(' '))

if a + b <= n:
    print(b)
else:
    print(n - a)
