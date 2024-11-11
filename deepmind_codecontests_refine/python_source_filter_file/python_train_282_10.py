n, k = map(int, input().split())
a = list(sorted(map(int, input().split()), reverse=True))
print(a)
cnt = 0
i, j = 1, 0

while i < n:
    if a[i] == a[j]:
        i += 1
        j += 1
    elif a[i] < a[j] <= a[i] + k:
        cnt += 1
        i += 1
    elif a[j] > a[i] + k:
        j += 1
        if j == i:
            i += 1

print(len(a) - cnt)
