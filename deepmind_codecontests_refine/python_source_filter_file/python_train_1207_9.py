import sys
input = sys.stdin.readline


n, k = map(int, input().split())
a = list(map(int, input().split()))

d = k
a = sorted(a)
cnt = 0
for i in range(n):
    while True:
        if a[i] / 2 < d:
            d = max(d, a[i])
            break
        else:
            cnt += 1
            d = 2 * d
print(cnt)