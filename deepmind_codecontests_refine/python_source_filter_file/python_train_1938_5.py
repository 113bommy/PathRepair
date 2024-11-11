(rmax, rmin) = map(int, input().split())
rmin = rmax - rmin

n = int(input())
rc = 0

for _ in range(n):
    (x, y, r) = map(abs, map(int, input().split()))
    if (x + r > rmax or y + r > rmax or
        (x + r < rmin and y + r < rmin)):
        continue
    if ((((x * x + y * y)**(.5) - r) >= rmin) and
         ((x * x + y * y)**(.5) + r) <= rmax):
        rc += 1

print(rc)
