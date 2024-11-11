n, x = map(int, input().split())
d = {}
for i in range(2 ** n):
    if not d.get(i, False):
        d[i ^ x] = 1
k = 0
print(len(d) - 1)
for i in range(1, 2**n):
    if i not in d:
        print(i, end=' ')
        k = i
