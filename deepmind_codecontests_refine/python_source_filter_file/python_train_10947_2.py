q = int(input())

for i in range(q):
    n = int(input())

    m = 0

    while n % 2 == 0:
        n = n / 2
        m += 1

    while n % 3 == 0:
        n = n / 3
        m += 2

    while n % 5 == 0:
        n = n / 5
        m += 3

    if n != 1:
        print(-1)
    else:
        print(m)
