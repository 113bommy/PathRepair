n = int(input())
a = list(map(int, input().split()))
s = sum(a)
if (2 * s) % (n * (n + 1)) != 0:
    print('NO')
else:
    t = (2 * s) // (n * (n + 1))
    for i in range(n - 1):
        k = a[i - 1] - a[i] + t
        if k % n or k < 0:
            print('NO')
            break
    else:
        print('YES')
