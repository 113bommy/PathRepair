n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    count = 0

    a, b = min(a, b), max(a, b)

    if a <= b // 2:
        count += a
    else:
        t = b - a
        count += t
        a -= t
        b -= t * 2

        if a > 2:
            count += a // 3 * 2
            if a % 3 == 2:
                count += 2
        elif a == 2 and b == 2:
            count += 1
    print(count)