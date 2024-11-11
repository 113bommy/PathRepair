n, m  = map(int, input().split())
j = []
for i in range(m):
    a = list(map(int, input().split()))
    b = list(a)
    b.sort()
    h = a.index(b[n - 1]) + 1
    j.append(h)
k = 0
for i in range(1, m + 1):
    if j.count(i) > j.count(k):
        k = i
print(k)
