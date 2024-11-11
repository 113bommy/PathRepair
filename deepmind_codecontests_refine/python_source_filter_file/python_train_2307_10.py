import bisect


n = int(input())
a = list(map(int, input().split()))
a = sorted(a)

ans = 0
for i in range(len(a)):
    if a[i] < 0:
        r = bisect.bisect_left(a, a[i] // 2)
        l = bisect.bisect_left(a, a[i] + 1)
        ans += r - l

        r = bisect.bisect_left(a, -a[i] * 2 + 1)
        l = bisect.bisect_left(a, -(a[i] // 2))

        ans += r - l

    elif a[i] > 0:
        r = bisect.bisect_left(a, 2 * a[i] + 1)
        l = bisect.bisect_left(a, a[i] + 1)
        ans += r - l
print(ans)

