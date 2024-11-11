q = int(input())

for i in range(q):
    n, m, k = map(int, input().split())
    if (n < m):
        n, m = m, n
    if (n % 2 == 0 and m % 2 != 0 or n % 2 != 0 and m % 2 == 0):
        n -= 1
        k -= 1
    elif (n % 2 == 0 and k % 2 != 0 or n % 2 != 0 and k % 2 == 0):
        k -= 2
        n -= 1
        m -= 1
    if (n > k):
        print(-1)
    else:
        print(k)