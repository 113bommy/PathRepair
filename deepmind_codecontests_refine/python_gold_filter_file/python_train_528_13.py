q = int(input())
for i in range(q):
    n, m, k = map(int, input().split())
    if max(n, m) > k:
        print(-1)
    elif (n + m) % 2 == 0:
        if n % 2 != k % 2:
            print(k - 2)
        else:
            print(k)
    else:
        print(k - 1)
