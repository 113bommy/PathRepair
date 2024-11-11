n, m = [int(s) for s in input().split()]
used = [0] * m
for i in range(n):
    left, right = [int(s) for s in input().split()]
    for j in range(left - 1,right):
        used[j] = 1
print(m - sum(used))
for i in range(1, m):
    if not used[i]:
        print(i + 1, end = ' ')