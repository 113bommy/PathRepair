def f(s):
    k = 0
    for el in b.values():
        k += el // s
    if k >= n:
        return True
    else:
        return False


n, m = map(int, input().split())
a = [int(i) for i in input().split()]
b = {}
for i in a:
    b[i] = b.get(i, 0) + 1
l = 0
r = 100
while r - l > 1:
    m = (l + r) // 2
    if f(m):
        l = m
    else:
        r = m
if not f(1):
    print(0)
else:
    print(l)