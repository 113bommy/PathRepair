t = int(input())

i = 0
while i < t:
    x, y, n = input().split(' ')
    x = int(x)
    y = int(x)
    n = int(n)

    n = n - y
    print((n - (n % x)) + y)

    i += 1

