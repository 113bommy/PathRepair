t = int(input())
for i in range(t):
    n, k = map(int, input().strip().split())
    ara = list(map(int, input().strip().split()))
    maxx = max(ara)

    for j in range(n):
        ara[j] = maxx - ara[j]

    if k % 2 == 0:
        maxx1 = max(ara)
        for j in range(n):
            ara[j] = maxx1 - ara[j]
    print(*ara, sep=" ")
