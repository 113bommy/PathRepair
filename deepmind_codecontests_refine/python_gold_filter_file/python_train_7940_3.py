from bisect import bisect_right
n, k = map(int, input().split())
a = [-2e9] + list(map(int, input().split())) + [2e9]
b = [0, n + 1]
if k:
    b = [0] + list(map(int, input().split())) + [n + 1]
k += 2
n += 2
for i in range(n):
    a[i] -= i
ans = 0
for i in range(1, k):
    if a[b[i]] - a[b[i - 1]] < 0:
        print(-1)
        exit()
    r = b[i]
    l = b[i - 1]
    cur = []
    for j in range(l + 1, r):
        if a[l] <= a[j] <= a[r]:
            ind = bisect_right(cur, a[j])
            if ind == len(cur):
                cur.append(a[j])
            else:
                cur[ind] = a[j]
    ans += r - l - 1 - len(cur)
print(ans)