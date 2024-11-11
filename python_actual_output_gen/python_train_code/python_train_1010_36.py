n, k = map(int, input().split())

if (k == 0 or k == n):
    print(0, 0)
else:
    if (3 * k > n):
        print(1, n - k)
    else:
        print(1, 3 * k)