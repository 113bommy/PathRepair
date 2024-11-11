n, w = map(int, input().split())
a = [int(i) for i in input().split()]
b = [0 for i in range(n + 1)]
b[0] = 0
for i in range(n):
    b[i + 1] = b[i] + a[i]
k = min(b)
if k < 0:
    for i in range(n + 1):
        b[i] -= k
if max(b) > w:
    print(0)
else:
    print(w - max(b) + 1)