import sys
input = sys.stdin.readline


n = int(input())
a = list(map(int, input().split()))

next = [n] * n
q = []
for i in range(n-1, -1, -1):
    while q and q[-1] > a[i]:
        q.pop()
    if q:
        next[i] = q[-1]
    q.append(i)
prev = [-1] * n
q = []
for i in range(n):
    while q and q[-1] > a[i]:
        q.pop()
    if q:
        prev[i] = q[-1]
    q.append(i)


right = [0] * n
for i in range(n-1, -1, -1):
    cnt = next[i] - i
    right[i] = a[i] * cnt
    j = next[i]
    if j < n:
        right[i] += right[j]

left = [0] * n
for i in range(n):
    cnt = i - prev[i]
    left[i] = a[i] * cnt
    j = prev[i]
    if j >= 0:
        left[i] += left[j]

best = 0
besti = -1
for i in range(n):
    cur = right[i] + left[i] - a[i]
    if cur > best:
        best = cur
        besti = i
ans = [0] * n
ans[besti] = a[besti]
mn = a[besti]
for i in range(besti + 1, n):
    mn = min(mn, a[i])
    ans[i] = mn
mn = a[besti]
for i in range(besti - 1, -1, -1):
    mn = min(mn, a[i])
    ans[i] = mn
print(*ans)