for t in range(int(input())):
    n = int(input())
    a = [*map(int, input().split())]
    a1, a2, a3, a4 = 0, 0, 0, 0
    res = 0 if n < 3 else int(not ((a[-3] > a[-2] > a[-1]) or (a[-3] < a[-2] < a[-1])))
    for i in range(n - 4, -1, -1):
        a1, a2, a3, a4 = a[i], a[i + 1], a[i + 2], a[i + 3]
        if not (a1 >= a2 >= a3 or a1 <= a2 <= a3):
            res += 1
        if min(a2, a3) < a4 < max(a2, a3) and min(a2, a3) < a1 < max(a2, a3):
            res += 1
    print(res + 2 * n - 1)