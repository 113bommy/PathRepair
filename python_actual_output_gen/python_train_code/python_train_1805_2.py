n = int(input())
a = [int(t) for t in input().split()]

max_len = 0
l = 0
for r in range(1, n + 1):
    if r == n or a[r] > a[l] * 2:
        max_len = max(max_len, r - l)
        l = r
print(max_len)
