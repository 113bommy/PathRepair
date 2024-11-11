n, m = [int(i) for i in input().split()]
a = [0]*101
for i in range(m):
    b = [int(i) for i in input().split()]
    a[b.index(max(b))] += 1
print(a.index(max(a)) + 1)