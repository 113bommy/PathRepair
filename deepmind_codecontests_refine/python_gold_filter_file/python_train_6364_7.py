n = int(input())
arr = list(map(int, input().split()))
arr.sort()

ap = float("inf")
at = -1
for t in range(1,101):
    s = 0
    for c in arr:
        s += max(abs(c - t) - 1, 0)
    if s < ap:
        ap = s
        at = t
print(at, ap)
