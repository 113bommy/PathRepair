n = int(input())
l1max = -1
r1min = 10**9 + 5
for _ in range(n):
    l, r = map(int, input().split(' '))
    l1max = max(l, l1max)
    r1min = min(r, r1min)
m = int(input())
l2max = -1
r2min = 10**9 + 5
for _ in range(m):
    l, r = map(int, input().split(' '))
    l2max = max(l, l2max)
    r2min = min(r, r2min)
print(max(0, l1max-r2min, l2max-r1min))