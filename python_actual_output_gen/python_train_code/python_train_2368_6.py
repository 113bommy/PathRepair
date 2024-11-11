n, k = map(int, input().split())

if k > 1:
    x = 1
    while 2**x <= n:
        x *= 2

    print(2*x-1)

else:
    print(n)

