q = int(input())

for i in range(q):
    k, n, a, b = [int(i) for i in input().split()]

    if k > b * n:
        if k > a * n:
            print(n)
        elif k == a * n:
            print(((k - b * n) // (a - b)) - 1)
        else:
            print((k - b * n) // (a - b))
    else:
        print(-1)
