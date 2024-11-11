n, v = map(int, input().split())

litre = v - 1

if v >= n - 1:
    print(v)
else:
    for i in range(1, n - v + 1):
        litre += i

    print(litre)