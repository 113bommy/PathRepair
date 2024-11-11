n, m = map(int, input().split())
a = list(map(int, input().split()))
asum = sum(a)
if m > asum:
    print(-1)
else:
    a.sort(reverse = True)
    for i in range(1, 100):
        task = 0
        for j in range(n):
            task += max(0, a[j] - j//i)
        if task >= m:
            print(i)
            break
