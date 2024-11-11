n, k = map(int, input().split())

if k > 1:
    x = 1
    while x <= n:
        x *= 2

    print(x-1)

else:
    print(n)

