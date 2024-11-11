from itertools import accumulate

n, t = map(int, input().split())
a = [0] * (t + 2)
for l, r in (map(int, input().split()) for _ in range(n)):
    a[l] += 1
    a[r + 1] -= 1
print(max(accumulate(a)))