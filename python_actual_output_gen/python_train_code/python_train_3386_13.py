n, x = list(map(int, input().split()))
t = 0
m = 0
for i in range(n):
    l, r = list(map(int, input().split()))
    if t < l:
        m += (r - l + 1) + (l - t + 1) % x
    t = r + 1
print(m)