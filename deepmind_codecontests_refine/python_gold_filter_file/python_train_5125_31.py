t = int(input())
for i in range(t):
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    cost = a[0]
    for j in range(1, n):
        if d >= a[j]*j:
            cost = cost + a[j]
            d = d - a[j]*j
        else:
            cost = cost + d // j
            break
    print(cost)
