n = int(input())
a = list(map(int, input().split()))

b = set()
i = a.__len__() - 1
c = 0

while i > 0:
    if not(a[i] in b):
        c = a[i]
        b.add(a[i])
    i -= 1
print(c)
