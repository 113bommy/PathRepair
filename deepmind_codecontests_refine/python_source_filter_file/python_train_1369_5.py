n = int(input())
a = [int(i) for i in input().split()]
page = 1
i = 0
c = 0
while i != n:
    while i != page - 1:
        i += 1
        page = max(page, a[i])
    i += 1
    if i != n:
        page = a[i]
    c += 1
print(c)
