q = int(input())
for i in range(q):
    n, m, k = map(int, input().split())
    if n < m:
        temp = n
        n = m
        m = temp
    if k < n:
        print(-1)
        q -= 1
        continue
    if n % 2 != m % 2:
        k -= 1
    elif n % 2 != k % 2:
        k -= 2
    print(k)
    q -= 1
