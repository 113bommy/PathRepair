n = int(input())
a = [int(i) for i in input().split()]

if n == 1:
    print(a[0], 0)
else:
    min_total = -1
    min_t = 0

    for t in range(min(a), max(a) + 1):
        total = 0
        for ai in a:
            total += max(abs(ai - t) - 1, 0)

        if min_total == -1 or total < min_total:
            min_total = total
            min_t = t

    print(min_t, min_total)
