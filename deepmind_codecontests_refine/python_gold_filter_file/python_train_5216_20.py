from bisect import bisect_left
n, l = int(input()), list(map(int, input().split()))
m, curr = 1, 1
for i in range(1, n):
    if l[i] <= l[i - 1] * 2:
        curr += 1
    else:
        curr = 1
    m = max(m, curr)
print(m)