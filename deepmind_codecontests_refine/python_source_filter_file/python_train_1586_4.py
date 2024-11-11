q = int(input())

for i in range(q):
    n, m = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    p = set([int(i) for i in input().split()])

    f = 0
    for i in range(n):
        for j in range(n - 1):
            if a[j] > a[j + 1]:
                if i + 1 not in p:
                    print('NO')
                    f = 1
                    break
                else:
                    a[j], a[j + 1] = a[j + 1], a[j]
            if f == 1:
                break
    if f == 1:
        continue

    print('YES')
