n, k = map(int, input().split())
a = list(map(int, input().split()))
c = []
x = a.copy()
for i in range(n):
    b = i + 1
    start = b - b // k - 1
    for j in range(start, n, k):
        x[j] = 0
    c.append(abs(x.count(-1) - x.count(1)))
    x = a.copy()
print(max(c))
