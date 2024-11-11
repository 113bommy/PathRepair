n = int(input())
a = list(map(int, input().split()))

if n == 1:
    print(a[0])
    exit(0)

min_idx = 0
min_res = a[0]
max_idx = 0
max_res = a[0]
for i in range(1, n):
    if a[i] < min_res:
        min_idx, min_res = i, a[i]
    if a[i] > max_res:
        max_idx, max_res = i, a[i]

res = 0
for i in range(n):
    if i != min_idx and i != max_idx:
        res += abs(a[i])

if min_res == max_res:
    res -= min_res

print(max_res + res - min_res)