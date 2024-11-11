from itertools import accumulate

n, r = map(int, input().split())
a = list(map(int, input().split()))

dom = list(map(lambda x: 0, range(n + 1)))

for i, el in enumerate(a):
    if el:
        dom[max(0, i - r + 1)] += 1
        dom[min(n, i + r)] -= 1

acc_d = list(accumulate(dom[:-1]))

if 0 in acc_d:
    print(-1)
    exit()

if n < r:
    print(1)
    exit()

right = -r
ans = 0
while right < n - 1:
    for i in range(right, min(n, right + 2 * r))[::-1]:
        if a[i]:
            right = i
            ans += 1
            break

print(ans)
