n, k = map(int, input().split())
if n // 2 > k or n == 1 and k != 0:
    print(-1)
elif n == 1 and k == 0:
    print(0)
else:
    ext = k - (n // 2) + 1
    ans = [ext, 2 * ext]
    n -= 2
    for i in range(1, 100001, 2):
        if n <= 1:
            break
        if i not in ans and i + 1 not in ans:
            print(i, i + 1, end=' ')
            n -= 2

    print(*ans, end=' ')
    if n & 1:
        print(1000000000)
