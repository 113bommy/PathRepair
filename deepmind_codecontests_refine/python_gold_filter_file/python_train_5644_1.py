import sys
from array import array  # noqa: F401


def input():
    return sys.stdin.buffer.readline().decode('utf-8')


n, k = map(int, input().split())
a = list(map(int, input().rstrip()))
visited = [0] * n
up, low = n + 1, n + 1

for i in range(n):
    if visited[i] or i + k >= n:
        break
    visited[i::k] = [1] * ((n - i + k - 1) // k)

    cnt = [0] * 10
    for j in range(i, n, k):
        cnt[a[j]] += 1
        if a[i] < a[j]:
            low = min(low, j)
        elif a[i] > a[j]:
            up = min(up, j)

    if cnt[a[i]] == sum(cnt):
        continue
    a[i::k] = [a[i]] * ((n - i + k - 1) // k)

if low < up:
    for i in range(k - 1, -1, -1):
        if a[i] != 9:
            a[i] += 1
            a[i::k] = [a[i]] * ((n - i + k - 1) // k)
            for j in range(i + 1, k):
                a[j::k] = [0] * ((n - j + k - 1) // k)
            for j in range(i + 1, n):
                if not visited[j]:
                    a[j] = 0
            break


print(n)
print(*a, sep='')
