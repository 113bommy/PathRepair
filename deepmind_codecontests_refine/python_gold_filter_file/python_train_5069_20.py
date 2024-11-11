def cut(a, n, b):
    odd_even = 0
    oe = []
    cost = []
    for i in range(n - 1):
        if a[i] % 2 == 0:
            odd_even += 1
        else:
            odd_even -= 1
        if odd_even == 0 and i != 0:
            oe.append(i)
            cost.append(abs(a[i + 1] - a[i]))

    cost.sort()
    i = 0
    while i < len(cost) and b - cost[i] >= 0:
        b -= cost[i]
        i += 1
    print(i)


n, b = map(int, input().split())
a = list(map(int, input().split()))

cut(a, n, b)
