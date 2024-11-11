n = int(input())

b = list(map(int, input().split()))

m, M = min(b), max(b)
if m == M:
    if M == 0:
        print('YES')
        print(' '.join(['1' for i in range(n)]))
    else:
        print('NO')
else:
    print('YES')

    pos = list(filter(lambda i: b[i] == M and b[i - 1] < M, range(n)))[0]

    a = [0 for i in range(n)]

    a[pos] = M
    a[pos - 1] = (M << 1) + b[pos - 1]

    for i in range(2, n):
        a[pos - i] = a[pos - i + 1] + b[pos - i]

    print(*a)
