n, k = map(int, input().split())
a = list(map(int, input().split()))
p = 1
max_p = 1
for i in range(1, n):
    if a[i] != a[i - 1]:
        p += 1
    else:
        if p > max_p:
            max_p = p
            p = 1
max_p = max(p, max_p)
print(max_p)