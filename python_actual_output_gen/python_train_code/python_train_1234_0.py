for _ in range(int(input())):
    n = int(input())
    *b, = map(int, input().split())
    b.sort()

    lres = 0
    rres = 0

    can_be_max = [-1] * n
    can_be_min = [-1] * n
    for i in range(n):
        if b[i] < 2 * i + 2 - i:
            can_be_max[i] = 0
            lres += 1
        else:
            can_be_max[i] = 1

        if b[n - i - 1] > 2 * n - 2 * i - 1 + rres:
            can_be_min[n - i - 1] = 0
            rres += 1
        else:
            can_be_min[n - i - 1] = 1

    ans = n + 1
    for i in range(n):
        if not can_be_min[i]:
            ans -= 1
        elif not can_be_max[i]:
            ans -= 1

    print(ans)


