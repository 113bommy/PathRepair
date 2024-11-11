for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    p = sorted(a)
    if a == p: print(0); break
    ans = 0
    for i in range(10 ** 7):
        if i % 2 == 0:
            for j in range(0, n - 1, 2):
                if a[j] > a[j + 1]:
                    a[j], a[j + 1] = a[j + 1], a[j]
        else:
            for j in range(1, n - 1, 2):
                if a[j] > a[j + 1]:
                    a[j], a[j + 1] = a[j + 1], a[j]
        if p == a: break
    print(i + 1)