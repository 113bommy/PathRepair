n = int(input())
a = list(map(int, input().split()))
ans = -1
if n < 3:
    ans = 0
elif n > 2:
    f = [(a[0],  a[1], 0), (a[0], a[1] - 1, 1), (a[0], a[1] + 1, 1), (a[0] - 1, a[1] - 1, 2), (a[0] - 1, a[1], 1),
         (a[0] - 1, a[1] + 1, 2), (a[0] + 1, a[1] - 1, 2), (a[0] + 1, a[1], 1), (a[0] + 1, a[1] + 1, 2)]
    mn = n
    for i in f:

        d = i[1] - i[0]
        k = i[2]
        b = i[1]
        for j in range(2, n):
            if a[j] - b == d:
                k = k
                b = a[j]
            elif a[j] - 1 - b == d:
                k += 1
                b = a[j] - 1
            elif a[j] + 1 - b == d:
                k += 1
                b = a[j] + 1
            else:
                break
            if j == n - 1:
                if k < mn:
                    ans = k
                    mn = k

print(ans)
