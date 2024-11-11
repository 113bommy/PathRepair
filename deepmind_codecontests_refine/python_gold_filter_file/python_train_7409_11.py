n, d = map(int, input().split())
a = list(map(int, input().split()))
cnt = 0
for i in range(len(a) - 1):
    if a[i + 1] <= a[i]:
        cnt += (a[i] - a[i + 1]) // d + 1
        a[i + 1] += d * ((a[i] - a[i + 1]) // d + 1)
print(cnt)
