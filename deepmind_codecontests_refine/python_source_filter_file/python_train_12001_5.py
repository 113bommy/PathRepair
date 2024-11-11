t = int(input())
for T in range(t):
    n, k = map(int, input().split())
    min = 10 ^ 4
    imin = 1
    a = [int(x) for x in input().split()]
    for i in range(n):
        if a[i] < min:
            min = a[i]
            imin = i
    ans = 0
    for i in range(n):
        if i != imin:
            ans += int((k - a[i]) / min)
    print(ans)
