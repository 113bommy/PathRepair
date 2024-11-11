n, a = map(int, input().split())
l = sorted(list(map(int, input().split())))
if len(l) == 1:
    print(0)
    exit()
m = float("inf")
if len(l) == 2:
    print(min(abs(a - l[0]), abs(a - l[1])))
    exit()
for i in [0, n-1]:
    if i == 0:
        x = abs(l[-1] - l[1]) + min(abs(a - l[1]), abs(a - l[-1]))
    else:
        x = abs(l[-2] - l[0]) + min(abs(a - l[0]), abs(a - l[-2]))
    if x < m:
        m = x
print(m)
