n = int(input())
a = [int(z) for z in input().split()]
cnt = 0
for i in range(1, n - 1):
    if a[i - 1] < a[i] and a[i + 1] < a[i]:
        cnt += 1
    if a[i - 1] > a[i] and a[i - 1] > a[i]:
        cnt += 1
print(cnt)