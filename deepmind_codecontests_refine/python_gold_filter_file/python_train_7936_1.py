# import time


def task(n, a):
    table = {}
    total = 0
    mx = 0
    for i in range(0, n):
        if not a[i] in table:
            table[a[i]] = 0
        table[a[i]] += 1
        mx = max(mx, a[i])

    for l in range(0, n - 1):
        suma = a[l]
        for r in range(l + 1, n):
            suma += a[r]

            if suma in table:
                total += table[suma]
                del table[suma]
            elif suma > mx:
                break

    print(total)


# start_time = time.time()
t = int(input())
for i in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    task(n, a)
# print("--- %s seconds ---" % (time.time() - start_time))
