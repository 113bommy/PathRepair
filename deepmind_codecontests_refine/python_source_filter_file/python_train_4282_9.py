n, s = map(int, input().split())
ar = list(map(int, input().split()))
m = min(ar)
x = 0
for i in ar:
    x += i - m
if x >= s:
    print(m)
else:
    left = s - x
    print(max(m - ((left - 1) % n + 1), -1))
